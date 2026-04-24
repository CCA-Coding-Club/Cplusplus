#include <iostream>
#include <cstdlib>

char yana = 'b';
//yes no function
int yloop() {
  for(int i = 0; i < 100; i++) {
    std::cin >> yana;
    if(yana == 'y' || yana == 'n') {
      break;
    }
  }
  return 0;
}

bool chloop = true;
char pchoice = '0';
//three choice function
int chfunc() {
  chloop = true;
  while(chloop) {
    std::cin >> pchoice;
    if(pchoice == '1' || pchoice == '2' || pchoice == '3') {
      chloop = false;
    }
    else{
      std::cout << "Please enter a valid option.";
    }
  }
  return 0;
}

auto cont = '0';

int main() {

  bool apple = false;
  bool spade = false;
  bool kloak = false;
  bool dep = false;

//section 1
  std::string test = "Greetings weary cyberskimmer! May I offer you some wares for the trials ahead?\n";
  std::cout << test;
  yloop();
  //std::cin.clear();
  if(yana == 'y') {
    std::cout << "Good choice skimmer. You may have one of three of my items in exchange for a little wisdom of yours.\n" << "1.Cyber-Apple ; 2. Spade ; 3. Kloak\n";
    while(chloop) {
    std::cin >> pchoice;
    if(pchoice == '1') {
      std::cout << "The apple appears in your hand.\n It seems to flash in and out of existence. A screen just in front of the merchants eyes flashes for roughly 15 seconds before he says.\n 'Thank you for your purchase.' And with that fades from your presence.\n";
      apple = true;
      chloop = false;
    }
    else if(pchoice == '2') {
      std::cout << "'Spade.' you say, the merchant grins.\n Suddenly he disappears and nothing can be seen but a void, I light flicks on, and behold, resting against a nearyby post is a spade. You make your way to it and pick it up. Upon brief examination you find a note taped to it.\n 'Thank you for your purchase.'\n";
      spade = true;
      chloop = false;
    }
    else if(pchoice == '3') {
      std::cout << "'Ah, the kloak.' Says the merchant dreamily. That be my favorite tool of the lot. I wouldn't try it on just yet if I was you skimmer. The merchant fades, or more acurrately, de-atomizes. and your ruck sack feels a bit heavier on your back.\n";
      kloak = true;
      chloop = false;
    }
    else{
      std::cout << "Pick an option skimmer.\n";
    }
    }
    }
  else if(yana == 'n') {
    std::cout << "Ahhh, a skimmer of the rough. Doesn't take a cup cause it might be poisoned. Very well, I will grant you a boon.\n He raises a robed arm palm facing you.\n The merchant's palm glows green. It gets brighter and brighter until only green covers your vision.\n";
    dep = true;
    }

  std::cin >> cont;
  std::system("clear");

  //section 2
  std::cout << "Soft. Fibers. 'Grass?' you think to yourself. You feel warmth on your arms and face.\n 'Where am I?'\n Thoughts come back. the words 'WELCOME BACK SKIMMER' fill my mind in vibrant green. My eyes shoot open at this unexpected occurance.\n You lay in a grassy field facing at a clear and sunny blue sky.\n What should I do first?\n 1. Get up and look around ; 2. Panic ; 3. Think and relax\n";
  chfunc();

}
