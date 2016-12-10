#ifndef JEU_2048_DOUBLE_HPP
#define JEU_2048_DOUBLE_HPP

#include <Jeu_2048.hpp>

// mode case x2
class Jeu_2048_double : public Jeu_2048
{
public:
    Jeu_2048_double(int x, int y);
    virtual ~Jeu_2048_double();
    bool getCaseDouble() const;
    virtual void unTour();
protected:
private:
    bool case_double;
};

#endif // JEU_2048_DOUBLE_HPP
