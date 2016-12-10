#ifndef JEU_2048_NEG_HPP
#define JEU_2048_NEG_HPP

#include <Jeu_2048.hpp>

// mode case négatif
class Jeu_2048_neg : public Jeu_2048
{
public:
    Jeu_2048_neg(int x, int y);
    bool getCaseNeg() const;
    virtual ~Jeu_2048_neg();
    virtual void unTour();

protected:
private:
    bool case_neg;
};

#endif // JEU_2048_NEG_HPP
