#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#define SICK system("cls");

std::string hangman_word()  
{
    int dynamic = time(0);
    srand(dynamic);
    std::string hangman_;

    std::fstream file;
    file.open("wordS.txt",std::ios::in);             //open to read and get size of file 
    std::string dummy;
    int max=0;                                      
    while(getline(file,dummy))
    {
        max++;
    }

    int random_number = (rand()%max)+1;


    file.close();
                                                        //open to get the random word
    file.open("words.txt",std::ios::in);

    int check=0;
    while(getline(file,dummy))
    {
        check++;
        if(check == random_number)
        {
            hangman_ = dummy;
            break;
        }
    }

    file.close();

return hangman_;   
}

void top()
{
    std::cout<<"\t /----------------------\\\n";
}

void bottom()
{
    std::cout<<"\t \\----------------------/\n";
}
void introduction(int life)
{
        top();
        std::cout<<"\t|\tHANGMAN\t    \t |"<<std::endl;
        bottom();
        std::cout<<std::endl;
        std::cout<<"        "<<"LIFE REMAINING---->"<<life<<std::endl;
        std::cout<<"\n\n";
}

void comparison(char user,std::string hangman, std::vector<char> &crt_words,int &life)
{
    bool flag = false;
    
    for(int i=0;i<hangman.size();i++)
    {
        if(user == hangman[i])                          //_ _ A _ _  replaces underscore with A
        {
            crt_words[i]=user;
            flag = true;                        // i got a word so no life minus 
        }
        

    }

    if(!flag)                                   //if user gave wrong word , the ncut 1 life
    {
        life--;
    }




}

void print_comparison(std::vector<char> crt_words)
{
    std::cout<<"\n\t";
    for(auto it : crt_words)
    {
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}

void diagram(int life,std::string hangman)
{
    switch(life)
    {
        case 8:
        {std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        break;
        }
        case 7:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        break;
        }
        case 6:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        break;
        }
        case 5:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |       O\n";
        std::cout<<"\t\t |\n";
        std::cout<<"\t\t |\n";
        break;
        }
         case 4:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |       O\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |\n";
        break;
        }
         case 3:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |       O\n";
        std::cout<<"\t\t |      /|\n";
        std::cout<<"\t\t |\n";
        break;
        }
        case 2:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |       O\n";
        std::cout<<"\t\t |      /|\\\n";
        std::cout<<"\t\t |\n";
        break;
        }
        case 1:
        {
        std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |       O\n";
        std::cout<<"\t\t |      /|\\\n";
        std::cout<<"\t\t |        \\\n";
        break;
        }
        case 0:
        {
             std::cout<<"\t\t --------\n";
        std::cout<<"\t\t |       |\n";
        std::cout<<"\t\t |       O\n";
        std::cout<<"\t\t |      /|\\\n";
        std::cout<<"\t\t |      / \\\n";
        std::cout<<"       \t GAME OVER              "<<std::endl;
        std::cout<<"the correct word is "<<hangman<<std::endl;
        break;
        }


        
        

    }
}









int main()
{
    int life = 8;
    bool end_program=false;
    char user;
    std::string hangman= hangman_word();           //hangman has word **
    std::vector<char> crt_words(hangman.size(),'_');        //pre initialize the size sith __

        //START
        SICK;
    for( life ; life>=0;)
    {
        
     
    introduction(life);                                //                    **
    diagram(life,hangman);
   print_comparison(crt_words);  
   std::cout<<"\n";                       //             **
    std::cout<<"        enter your letter :";
    std::cin>>user;
    user = toupper(user);
    comparison(user,hangman,crt_words,life);


    
    for(int check=0; check<crt_words.size();check++)
    {
        if(hangman[check]==crt_words[check])
        {
            end_program = true;             //BL__K means 
        }
        else{
            end_program = false;
            break;                      //if underscore present no need to check again
        }
            
    }

    
    if(end_program)
    {
        print_comparison(crt_words);
        std::cout<<"\n    YOU WON AND SAVED HIS LIFE!!!!!!"<<std::endl;
        break;
    }
    else
    {
        
    SICK;
    }
    

    
    }
}