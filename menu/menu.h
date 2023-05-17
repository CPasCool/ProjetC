typedef struct choixMenu_ choixMenu;
int menu();


void lancementMenu(choixMenu*);
void setChoixMenu(choixMenu*,int);
choixMenu* createChoixMenu();
void setChoixMenu(choixMenu*, int);
choixMenu* getChoixMenu(choixMenu*);
int getChoix(choixMenu*);
void afficheMenu(int);
