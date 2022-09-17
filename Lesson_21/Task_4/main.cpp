#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

struct position
{
    int pos_x,pos_y;
};

struct enemy
{
    std::string name_enemy;
    position pos_enemy;
    char status{'a'};                           //alive-a dead-d
    int health = 50 + (rand() % 101);
    int armor = rand() % 51;
    int damage = 15 + (rand() % 16);
};

struct character
{
    std::string name_hero;
    position pos_hero;
    int health;
    int armor;
    int damage;
};

int attack_hero(int x , int y , enemy (&foe)[5],character & hero,char (&field)[20][20])
{
    int i(0);
    for (; i<5 ; i++)
    {
        if (foe[i].pos_enemy.pos_x==x)
        {
            if (foe[i].pos_enemy.pos_y==y) break;
        }
    }
    if (foe[i].armor<hero.damage)
    {
        foe[i].health=foe[i].health+foe[i].armor-hero.damage;
        if ( foe[i].health<=0) { foe[i].status='d'; field[foe[i].pos_enemy.pos_x][foe[i].pos_enemy.pos_y]='.'; }
        else foe[i].armor=0;
    }
    else foe[i].armor-=hero.damage;
}

void attack_enemy(int x , int y , enemy &foe,character & hero)
{
    if (hero.armor<foe.damage)
    {
        hero.health=hero.health+hero.armor-foe.damage;
        hero.armor=0;
    }
    else hero.armor-=foe.damage;
}

void write_field(char (&field)[20][20])
{
    for (int i(0) ; i<20 ; i++)
    {
        for (int j(0) ; j<20 ; j++)
        {
            std::cout << field[j][i] << "  ";
        }
        std::cout << std::endl;
    }
}

int main()
{

    srand( time(0));
    const int SIZE = 20;
    char field[SIZE][SIZE];
    char move;
    std::memset(field, '.', SIZE * SIZE);
    enemy foe[5]={{"Enemy #1"},
                  {"Enemy #2"},
                  {"Enemy #3"},
                  {"Enemy #4"},
                  {"Enemy #5"}};
    character hero;

    std::cout << "A turn-based role-playing game welcomes you." << std::endl;
    std::cout << "Enter the name of the character: ";
    std::cin >> hero.name_hero;
    std::cout << "Enter the amount of health: ";
    std::cin >> hero.health;
    std::cout << "Enter the amount of armor: ";
    std::cin >> hero.armor;
    std::cout << "enter the damage strength: ";
    std::cin >> hero.damage;

    hero.pos_hero={rand()%20,rand()%20};
    field[hero.pos_hero.pos_x][hero.pos_hero.pos_y]='P';
    for (int i(0) ; i<5 ; i++ )
    {
        while(true)
        {
            int x = rand() % 20;
            int y = rand() % 20;
            if (field[x][y]=='.')
            {
                field[x][y]='E';
                foe[i].pos_enemy={x,y};
                break;
            }
        }
    }


    while(true)
    {
        write_field(field);
        std::cout << "Make a character move (w,a,s,d)(save-1/load-2):";
        std::cin >> move;

        if (move=='1')
        {
            std::ofstream file("save.bin", std::ios::binary);
            if (file.is_open())
            {
                for (int i = 0; i < 5; ++i) file.write((char *) &(foe[i].pos_enemy),sizeof(foe[i].pos_enemy));
                file.write((char *) &(hero.pos_hero),sizeof(hero.pos_hero));
                continue;
            }
            else std::cout<<"Error.";
        }
        else if (move=='2')
        {
            std::ifstream file("save.bin", std::ios::binary);
            if (file.is_open())
            {
                for (int i = 0; i < 5; ++i) file.read((char *) &(foe[i].pos_enemy),sizeof(foe[i].pos_enemy));
                file.read((char *) &(hero.pos_hero),sizeof(hero.pos_hero));
                std::memset(field, '.', SIZE * SIZE);
                field[hero.pos_hero.pos_x][hero.pos_hero.pos_y]='P';
                for (int k(0) ; k<5 ; k++)
                {
                    field[foe[k].pos_enemy.pos_x][foe[k].pos_enemy.pos_y]='E';
                }
                continue;
            }
            else std::cout<<"Error.";
        }
        else if (move=='w')
        {
            if(hero.pos_hero.pos_y==0) continue;
            else
            {
                if (field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y-1)]=='E')
                {
                    attack_hero(hero.pos_hero.pos_x,(hero.pos_hero.pos_y-1),foe,hero,field);
                }
                else
                {
                    field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y)]='.';
                    field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y - 1)]='P';
                    hero.pos_hero.pos_y-=1;
                }
            }
        }
        else if (move=='s')
        {
            if(hero.pos_hero.pos_y==19) continue;
            else
            {
                if (field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y+1)]=='E')
                {
                    attack_hero(hero.pos_hero.pos_x,(hero.pos_hero.pos_y+1),foe,hero,field);
                }
                else
                {
                    field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y)]='.';
                    field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y + 1)]='P';
                    hero.pos_hero.pos_y+=1;
                }
            }
        }
        else if (move=='a')
        {
            if(hero.pos_hero.pos_x==0) continue;
            else
            {
                if (field[(hero.pos_hero.pos_x-1)][hero.pos_hero.pos_y]=='E')
                {
                    attack_hero((hero.pos_hero.pos_x-1),(hero.pos_hero.pos_y),foe,hero,field);
                }
                else
                {
                    field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y)]='.';
                    field[(hero.pos_hero.pos_x-1)][hero.pos_hero.pos_y]='P';
                    hero.pos_hero.pos_x-=1;
                }
            }
        }
        else if (move=='d')
        {
            if(hero.pos_hero.pos_x==19) continue;
            else
            {
                if (field[(hero.pos_hero.pos_x+1)][hero.pos_hero.pos_y]=='E')
                {
                    attack_hero((hero.pos_hero.pos_x+1),(hero.pos_hero.pos_y),foe,hero,field);
                }
                else
                {
                    field[hero.pos_hero.pos_x][(hero.pos_hero.pos_y)]='.';
                    field[(hero.pos_hero.pos_x+1)][hero.pos_hero.pos_y]='P';
                    hero.pos_hero.pos_x+=1;
                }
            }
        }
        else { std::cout<<"error"; continue;}

        for (int j(0) ; j<5 ; j++ )
        {
            if (foe[j].status=='d') continue;
            int number=rand()%4;
            switch (number)
            {
                case 0:
                {
                    if (foe[j].pos_enemy.pos_y==0) break;
                    else
                    {
                        if ( field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y-1)]=='P' )
                        {
                            attack_enemy(foe[j].pos_enemy.pos_x,(foe[j].pos_enemy.pos_y-1),foe[j],hero);
                        }
                        else if (field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y-1)]=='E') break;
                        else
                        {
                            field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y)]='.';
                            field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y-1)]='E';
                            foe[j].pos_enemy.pos_y-=1;
                        }
                    }
                    break;
                }
                case 1:
                {
                    if (foe[j].pos_enemy.pos_y==19) break;
                    else
                    {
                        if ( field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y+1)]=='P' )
                        {
                            attack_enemy(foe[j].pos_enemy.pos_x,(foe[j].pos_enemy.pos_y+1),foe[j],hero);
                        }
                        else if (field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y+1)]=='E') break;
                        else
                        {
                            field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y)]='.';
                            field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y+1)]='E';
                            foe[j].pos_enemy.pos_y+=1;
                        }
                    }
                    break;
                }
                case 2:
                {
                    if (foe[j].pos_enemy.pos_x==0) break;
                    else
                    {
                        if ( field[(foe[j].pos_enemy.pos_x-1)][(foe[j].pos_enemy.pos_y)]=='P' )
                        {
                            attack_enemy((foe[j].pos_enemy.pos_x-1),(foe[j].pos_enemy.pos_y),foe[j],hero);
                        }
                        else if (field[(foe[j].pos_enemy.pos_x-1)][(foe[j].pos_enemy.pos_y)]=='E') break;
                        else
                        {
                            field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y)]='.';
                            field[(foe[j].pos_enemy.pos_x-1)][(foe[j].pos_enemy.pos_y)]='E';
                            foe[j].pos_enemy.pos_x-=1;
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (foe[j].pos_enemy.pos_x==19) break;
                    else
                    {
                        if ( field[(foe[j].pos_enemy.pos_x+1)][(foe[j].pos_enemy.pos_y)]=='P' )
                        {
                            attack_enemy((foe[j].pos_enemy.pos_x+1),(foe[j].pos_enemy.pos_y),foe[j],hero);
                        }
                        else if (field[(foe[j].pos_enemy.pos_x+1)][(foe[j].pos_enemy.pos_y)]=='E') break;
                        else
                        {
                            field[foe[j].pos_enemy.pos_x][(foe[j].pos_enemy.pos_y)]='.';
                            field[(foe[j].pos_enemy.pos_x+1)][(foe[j].pos_enemy.pos_y)]='E';
                            foe[j].pos_enemy.pos_x+=1;
                        }
                    }
                    break;
                }
                default: std::cout << "Error";
            }
        }
        if (hero.health<=0) { std::cout << "Defeat. Your character is dead!"; break; }
        if ( (foe[0].status==foe[1].status) && (foe[1].status==foe[2].status) && (foe[2].status==foe[3].status) && (foe[0].status=='d') )
        {
            std::cout << "You have won!!!";
            break;
        }
    }
    return 0;
}



