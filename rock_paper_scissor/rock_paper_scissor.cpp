/*
The line std::cout << "\r"; moves the cursor to the beginning of the line but doesn't actually overwrite or erase the prompt text. You need to clear the line after input by filling the en
tire line with 
spaces, then moving the
 cursor back to the beginning.
 
 
 
  std::cin.ignore();                                      //IGNORE DEFAULT NEWLINE
            std::cin.get();                                         //GETS 1 CHARACTER AS INPUT BUT DIDNT STORE ANYWHERE*/


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

#define SICK system("cls");
void top()
{
    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"|                                            |"<<std::endl; 
}

void bottom()
{
    std::cout<<"|                                            |"<<std::endl; 
    std::cout<<"----------------------------------------------"<<std::endl;
}

void introduction(std::string name)
{
    top();
    std::cout<<"|   ROCK -R        PAPER-P        SCISSOR-S  |"<<std::endl;
    bottom();
    std::cout<<"     "<<name<<"\t\t\t"<<"     computer "<<std::endl;
    
}

char cse_choice()
{
    
    if(((rand()%3)+1) ==1)
    {
        return 'R';
    }

    else if(((rand()%3)+1 )==2)
    {
        return 'P';
    }

    else{
        return 'S';
    }

}

void show_choices (char user_choice, char computer_choice)
{
    std::cout<<"choice:"<<user_choice<<"                    choice:"<<computer_choice<<std::endl;
}


void show_result(char user_choice, char computer_choice,std::string name,int &computer_score,int &user_score)
{
    if(user_choice =='R' )
    {
       switch(computer_choice)
       {
        case 'R':
        {
            std::cout<<"-----------------  DRAW ------------------------\n";
           break;
        }

        case 'P':
        {
            std::cout<<"----------------- COMPUTER WINS ------------------------";
           computer_score++;
            break;
        }
        default:
        {
             std::cout<<"-----------------"<<name<<" WINS------------------------";
            user_score++;
            break;
        }
       }
    }

    else if(user_choice =='P' )
    {
       switch(computer_choice)
       {
        case 'R':
        {
             std::cout<<"-----------------"<<name<<" WINS------------------------";
            user_score++;
           break;
        }

        case 'P':
        {
            std::cout<<"-----------------  DRAW ------------------------\n";
            break;
        }
        default:
        {
            std::cout<<"----------------- COMPUTER WINS ------------------------";
           computer_score++;
            break;
        }
       }
    }

     else if(user_choice =='S' )
    {
       switch(computer_choice)
       {
        case 'R':
        {
            std::cout<<"----------------- COMPUTER WINS ------------------";
             computer_score++;
           break;
        }

        case 'P':
        {
             std::cout<<"-----------------"<<name<<" WINS-----------------";
             user_score++;
            break;
        }
        default:
        {
            std::cout<<"-----------------  DRAW ------------------------\n";
            break;
        }
       }
    }

    else{
        SICK;
        std::cout<<"enter correct number "<<std::endl;
    }
}

void scoreboard(int computer_score,int user_score)
{
    std::cout<<std::endl;
    top();
    std::cout<<"|SCORE:"<<user_score<<"                    SCORE:"<<computer_score<<"|"<<std::endl;
    bottom();
}




int main()
{
    int computer_score=0,user_score=0;
    SICK;
//SEEDING IT HERE SO THT IT WONT RESET EACH TIME CALLING FUNCTION 
    int dynamic = time(0);
    srand(dynamic);
    std::string name;
    char user_choice;                                   //user choice
    //**************** */
    
    std::cout<<"enter your name:";
    std::cin>>name;

    
    bool  flag=true;
       
    while( flag)
    {
    char computer_choice= cse_choice();                 //cse choice generates new each time 
        introduction(name);                             //*
        std::cout<<"enter ur choice:";
        std::cin>>user_choice;
        
        
        user_choice = toupper(user_choice);
        show_choices(user_choice,computer_choice);


        //calculation and tell who wins , computer or user

        show_result(user_choice,computer_choice,name,computer_score,user_score);

        // gives the score for both 
        
        scoreboard(computer_score,user_score);


        //IF ANY ONE WINS , THEN WHILE LOOP TERMINATES 

        if(user_score ==3 || computer_score ==3)        //to stop rpogram if anyone wins
        {

            flag=false;
             show_result(user_choice,computer_choice,name,computer_score,user_score);
          }
        else{
            flag==true;  
            std::cout<<"enter any key to continue next round:"; 
            std::cin.ignore();                                      //IGNORE DEFAULT NEWLINE
            std::cin.get();                                         //GETS 1 CHARACTER AS INPUT BUT DIDNT STORE ANYWHERE
            SICK;                                                   //CLEARS SCREEN
            
        }


        


        
        
        

        
    }


}