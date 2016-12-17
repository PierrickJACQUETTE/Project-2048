#ifndef JEU_2048_DESTROY_HPP
#define JEU_2048_DESTROY_HPP

#include <Jeu_2048.hpp>

// mode case détruit
class Jeu_2048_destroy : public Jeu_2048
{
public:
    Jeu_2048_destroy(int x, int y);
    ~Jeu_2048_destroy();
    bool getCaseDestroy() const;
    void unTour(int);
protected:
private:
    bool case_destroy;
};

#endif // JEU_2048_DESTROY_HPP
