#include "Warlock.hpp"

// 00
// int main()
// {
//   Warlock const richard("Richard", "Mistress of Magma");
//   richard.introduce();
//   std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

//   Warlock* jack = new Warlock("Jack", "the Long");
//   jack->introduce();
//   jack->setTitle("the Mighty");
//   jack->introduce();

//   delete jack;

//   return (0);
// }


// 01
#include "Dummy.hpp"
#include "Fwoosh.hpp"
// int main()
// {
//   Warlock richard("Richard", "the Titled");

//   Dummy bob;
//   Fwoosh* fwoosh = new Fwoosh();

//   richard.learnSpell(fwoosh);

//   richard.introduce();
//   richard.launchSpell("Fwoosh", bob);

//   richard.forgetSpell("Fwoosh");
//   richard.forgetSpell("Fwoosh");
//   richard.forgetSpell("Fwoosh");
//   richard.forgetSpell("Fwoosh");
//   richard.forgetSpell("Fwoosh");
//   richard.forgetSpell("Fwoosh");
//   richard.launchSpell("Fwoosh", bob);

//   delete fwoosh;
// }


// 02
#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"

// int main()
// {
//   Warlock richard("Richard", "foo");
//   richard.setTitle("Hello, I'm Richard the Warlock!");
//   BrickWall model1;

//   Polymorph* polymorph = new Polymorph();
//   TargetGenerator tarGen;

//   tarGen.learnTargetType(&model1);
//   richard.learnSpell(polymorph);

//   Fireball* fireball = new Fireball();

//   richard.learnSpell(fireball);

//   ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

//   richard.introduce();
//   richard.launchSpell("Polymorph", *wall);
//   richard.launchSpell("Fireball", *wall);

// 	delete fireball;
// 	delete polymorph;
// }


int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");

  Dummy t;
  ASpell* p = new Polymorph();
  richard.learnSpell(p);
  richard.launchSpell("Polymorph", t);

  delete p;
}
