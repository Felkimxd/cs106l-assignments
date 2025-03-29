#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  auto it_beg = source.begin();
  auto it_end = source.end();

  auto pointer_vec = find_all(it_beg, it_end,isspace);

  pointer_vec.push_back(it_end); // Add the end of the string to the vector
  pointer_vec.insert(pointer_vec.begin(), it_beg); // Add the beginning of the string to the vector
  
  std::set<Token> tokens;

  std::transform(pointer_vec.begin(), 
  pointer_vec.end()-1, 
  pointer_vec.begin() + 1, 
  std::inserter(tokens, tokens.end()), 

  [&source](auto it1, auto it2){ 
    return Token{source, it1, it2};
  }
  );

  std::erase_if(tokens,
                [](auto &token)
                {
                  return token.content.empty();
                });
  /* TODO: Implement this method */
  return Corpus(tokens);
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto filtered_tokens = source | rv::filter([&dictionary](const Token &token){ 
  return !dictionary.contains(token.content); 
  });

  std::set<Mispelling> result;

  auto misspelling_view = filtered_tokens | rv::transform([&dictionary](const Token &token){
    auto suggestions_view = dictionary | rv::filter([&token](const std::string &word){ 
      return levenshtein(token.content, word) == 1; 
    });
    
    std::set<std::string> suggestions(suggestions_view.begin(), suggestions_view.end());
    return Mispelling{token, suggestions};
  });

  auto empty_suggestions = misspelling_view | rv::filter([](const Mispelling &mispelling){ 
    return !mispelling.suggestions.empty(); 
  });
  return std::set<Mispelling>(empty_suggestions.begin(), empty_suggestions.end());
};

/* Helper methods */

#include "utils.cpp"