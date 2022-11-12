#include "header.h"

int main()
{

    int numberCommands , numberTeam ;

    std::cout << "Simulation of the company's work!" << std::endl ;
    std::cout << "Enter the number of commands: " ;
    std::cin >> numberCommands ;
    std::cout << "Enter the number of employees in the team: " ;
    std::cin >> numberTeam ;

    HeadCompany head;
    MiddleManager manager[numberCommands] ;
    Subordinates people[numberCommands][numberTeam] ;

    do
    {
        for (int i(0); i < numberCommands; i++)
        {
            manager[i].setTask(i, head.getInstructions(), numberTeam);
        }

        for (int i(0); i < numberCommands; i++)
        {
            int j ( manager[i].getFreeEmployee() );
            for ( ; ( (j < (manager[i].getTaskCount() + j)) && (j < numberTeam) ); j++ )
            {
                people[i][j].setSubTask();
            }
            manager[i].setFreeEmployee(j);
        }

    }
    while(head.getAllTask(numberCommands,manager,numberTeam));

    return 0;
}
