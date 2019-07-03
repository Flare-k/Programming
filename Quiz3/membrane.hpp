#include "keyboard.hpp"
class membrane: public keyboard{
public:
    membrane(int _numkey, string _language);
    ~membrane();
    void print() override;
};
