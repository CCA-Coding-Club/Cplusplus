#include <iostream>
auto yn = 'b';
int yloop() {
  for(int i = 0; i < 100; i++) {
    std::cin >> yn;
    if(yn == 'y' || yn == 'n') {
      break;
  return 0;
    }
  }
}

int main() {
  bool apple = false
  bool spade = false
  bool kloak = false
  bool dep = false


  std::string test = "Greetings weary cyberskimmer! May I offer you some wares for the trials ahead?\n";
  std::cout << test;
  yloop();
  if(yn == 'y') {
    std::cout << "Good choice skimmer. You may have one of three of my items in exchange for a little wisdom of yours.\n" << "1.Cyber-Apple ; 2. Spade ; 3. Kloak\n";
    int pchoice = 0;
    std::cin >> pchoice;
    if(pchoice == 1) {
      std::cout << "The apple appears in your hand. it seems to flash in and out of existence. The screen just in front of the merchants eyes flashes for roughly 15 seconds before he says. Thank you for your purchase. He fades from your presence\n";
      apple = true;
    }
    if(pchoice == 2) {
      std::cout << "'Spade.' you say, the merchant grins. Suddenly he disappears and nothing can be seen but a void, I light flicks on, and behold, resting against a nearyby post is a spade. You make your way to it and pick it up. Upon brief examination you find a note taped to it. 'Thank you for your purchase.'\n";
      spade = true;
    }
    if(pchoice == 3) {
      std::cout << "'Ah, the kloak.' Says the merchant dreamily. That be my favorite tool of the lot. I wouldn't try it on just yet if I was you skimmer. The merchant fades, or more acurrately, deatomizes. and your ruck sack feels a bit heavier on your back.\n";
      kloak = true
    }
    }}