typedef struct choixMenu_ choixMenu;


void setChoixMenu(choixMenu*,int);
choixMenu* createChoixMenu();
void setChoixMenu(choixMenu*, int);
choixMenu* getChoixMenu(choixMenu*);
int getChoix(choixMenu*);
void afficheMenu(int);
void menu();
