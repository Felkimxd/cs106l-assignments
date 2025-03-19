#include<string>

class Plant
{
private:
    std::string name;
    std::string specie;
    int leaveNum;
    bool flowers;
    bool fruits;

    void photosyntesis();
    void fallingLeaves();


public:
    Plant(std::string name, std::string specie, int leave_num, bool flowers, bool fruits);
    
    Plant()
    {
        name = "Insert name";
        specie = "Insert specie";
        leaveNum = 0;
        flowers = false;
        fruits = false;
    };

    std::string const getName();
    int  const getLeavesNum ();
    bool const getFlowersExists();
    bool const getFruitsExists();

    void setName(const std::string name);
    void setSpecie(const std::string specie);
    void setNumLeaves(int leaves);
    void setFlowers(bool flowers);
    void setFruits(bool fruits);
    void treeLive();
};