// classes example
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm> // use abs() needed for sort
#include <random>
#include <string>



// EXAMINATION COMMENT.   YEAR PERFORMANCE REGULARITY, HOMEWORK IF BAD. ABILITIES AND POTENTIAL. REVISION AND END.


//#include <string> //
//#include<math.h> // use sqrt()



#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;





//**********************************************************************************
// main function
//**********************************************************************************
int main( int argc, const char* argv[] )
{
    std::cout << endl ;
    std::cout << BOLDYELLOW << "    _________________________________________________" << std::endl ;
    std::cout << BOLDYELLOW << "            _=_                                      " << RESET << std::endl ;
    std::cout << BOLDYELLOW << "          q(-_-)p                                    " << RESET << std::endl ;
    std::cout << BOLDYELLOW << "          '_) (_`         REPORT GENERATOR        " << RESET << std::endl ;
    std::cout << BOLDYELLOW << "          /__/  \\         Carles Triguero 2023      " << RESET << std::endl ;
    std::cout << BOLDYELLOW << "        _(<_   / )_                                  " << RESET << std::endl ;
    std::cout << BOLDYELLOW << "       (__\\_\\_|_/__)                               " << RESET << std::endl ;
    std::cout << BOLDYELLOW << "    _________________________________________________" << RESET << std::endl ;
    std::cout << endl ;
    
    
    
    
        // Check the number of arguments (1 means only the name of the program => No argument)
        if ( argc == 1 )
        {
            cout << "\t Wrong usage. You should execute:" << endl ;
            cout << BOLDRED << "\t " << argv[0] << " [File to analyze.dat]" << RESET << endl ;
            cout << " " << endl ;
            return (0) ;
        }
    
        // Check if the file exists
        ifstream file(argv[1]) ;
        if (!file)
        {
            std::cout << BOLDRED <<"    -> ERROR: File test.xyz does not exist. ABORTING" << RESET << std::endl ;
            std::cout << std::endl ;
            abort () ;
        }
        file.close() ;
    
        std::cout << YELLOW << "    -> File " << BOLDYELLOW << argv[1] << RESET << YELLOW << " found" << RESET << std::endl ;
    
        unsigned int bins = 100 ;        // Number of bins default
    
        for ( int k = 1; k < argc ; ++k )
        {
            if ( ( argv[k] == std::string("-h") ) || ( argv[k] == std::string("-HELP") ) || ( argv[k] == std::string("-H") ) || ( argv[k] == std::string("-help") ) )
            {
                cout  << BOLDBLACK << "    HELP:" << RESET << std::endl ;
                cout << "    Generates a histogram with the second column of a file containing real data" << std::endl ;
                cout << "    [Column can be changed and also addapted to integer data]" << std::endl ;
                cout << "    ------------------------------------------------" << std::endl ;
                cout << BOLDBLACK << "    Execution: ./a.out file.dat [+flags]" << RESET << std::endl ;
                cout << BOLDBLACK << "    Mandatory flags:" << RESET << std::endl ;
                cout << "    -bins" << "\t" << "    to set the number of bins (e.g. ./a.out file.dat -bins 100) default bins=100" << std::endl ;
                cout << BOLDBLACK << "    Optional flags:" << RESET << std::endl ;
                cout << "    -h" << "\t" << "    to get help  (e.g. ./a.out -help)" << std::endl ;
                cout << "    -gle" << "\t" << "    to generate gle graphs of histogram and PDF  (e.g. ./a.out file.dat -bins 100 -gle)" << std::endl ;
                cout << std::endl ;
                return (0) ;
            }
            if ( ( argv[k] == std::string("-bins") ) || ( argv[k] == std::string("-bin") )  || ( argv[k] == std::string("-b") ) ) { bins = atoi(argv[k+1]) ; }
            //        if ( ( argv[k] == std::string("-gle") ) || ( argv[k] == std::string("-g") )  || ( argv[k] == std::string("-GLE") ) ) { Ly = atoi(argv[k+1]) ; }
        }
    
    
    
        // Count execution time
        int start_s=clock();
    
    
    
        // // Files to store data
        // ofstream Reports ;
        // Reports.open ("Reports.txt", ios::out | ios::trunc); // Report file to copy and paste on sims
    
    
    
    
    
        // Input file definition
        std::string File(argv[1]); // set up a stringstream variable named convert, initialized with the input from argv[1]
    
    
        cout << YELLOW << "    -> Processing file: " << BOLDYELLOW << File << RESET << endl ;
    
    
    
    
    
        // Data file input to read
        std::ifstream InputFile ;
        InputFile.open( File.c_str(), ios::in );
    
        std::string line ;            // variable string to read the line
    
  
    
        std::vector<double> DataVector ;
    
    
        std::vector<std::string> res;
        res.push_back ("consequence") ;
        res.push_back ("result") ;
        res.push_back ("outcome") ;
    
    
    
    
    std::vector<std::string> top;
    top.push_back ("an outstanding") ;
    top.push_back ("an exceptional") ;
    top.push_back ("an impressive") ;


    std::vector<std::string> tops;
    tops.push_back ("outstanding") ;
    tops.push_back ("exceptional") ;
    tops.push_back ("impressive") ;


    
    std::vector<std::string> Excellence;
    Excellence.push_back ("an excellent") ;
    Excellence.push_back ("a superb") ;
    Excellence.push_back ("a fabulous") ;
 //        Excellence.push_back ("Impresive") ;
    
    
    
    std::vector<std::string> Goodness;
    Goodness.push_back ("a very good") ;
    Goodness.push_back ("a great") ;
    Goodness.push_back ("a remarkable") ;
    
    
    std::vector<std::string> MediumHigh;
    MediumHigh.push_back ("a good") ;
    MediumHigh.push_back ("an adequate") ;
    // MediumHigh.push_back ("an acceptable") ;
    MediumHigh.push_back ("a satisfactory") ;
    
    
    std::vector<std::string> MediumLow;
    MediumLow.push_back ("a fair") ;
    MediumLow.push_back ("a modest") ;
    MediumLow.push_back ("an acceptable") ;
    // MediumLow.push_back ("a satisfactory") ;
    // decent
    
    std::vector<std::string> Badness;
    Badness.push_back ("a disappointing") ;
    Badness.push_back ("a discouraging") ;
    Badness.push_back ("an unsatisfactory") ;

     // Badness.push_back ("a modest") ;
    // Badness.push_back ("a limited") ;
    
    
    
    std::vector<std::string> Achi;
    Achi.push_back ("achieved") ;
    Achi.push_back ("attained") ;
    Achi.push_back ("reached") ;
    //Achi.push_back ("secured") ;
//    MdeUp //satisfactory
    
    
    std::vector<std::string> Hard;
    Hard.push_back ("difficult") ;
    Hard.push_back ("challenging") ;
    
    
    
    std::vector<std::string> AsRequired;
    AsRequired.push_back ("in different situations") ;
    AsRequired.push_back ("as required") ;
    AsRequired.push_back ("appropriately") ;
    AsRequired.push_back ("to good effect") ;
    AsRequired.push_back ("according to need") ;
    AsRequired.push_back ("as needed") ;
    // pro re nata
    
    std::vector<std::string> heshe;
    heshe.push_back ("she") ;
    heshe.push_back ("he") ;
    
    std::vector<std::string> Cheshe;
    Cheshe.push_back ("She") ;
    Cheshe.push_back ("He") ;
    
    std::vector<std::string> hisher;
    hisher.push_back ("her") ;
    hisher.push_back ("his") ;

    std::vector<std::string> Chisher;
    Chisher.push_back ("Her") ;
    Chisher.push_back ("His") ;
    
    std::vector<std::string> topikini;
    topikini.push_back ("topic") ;
    topikini.push_back ("topics") ;
    int toto, alltopics ;
    

    
    // random initialise  vect{ 10, 20, 30 };
    srand ( time(NULL) );
    
    int choicesa6,choicesb6,choicesc6,choicesd6;
    int choicesa5,choicesb5,choicesc5,choicesd5;
    int choicesa4,choicesb4,choicesc4,choicesd4;
    int choicesa3,choicesb3,choicesc3,choicesd3;
    int choicesa2,choicesb2,choicesc2,choicesd2;
    
    
    // BOUNDARIES

    // A*  85+
    // A   70-84
    // B   60-69
    // C*  50-59
    // C   35-49
    // D   25-34
    // E   <25
    
    // 2 A* Levels
    // 1 A level
    // 1 B level
//     A	79.5
// B	67.5
// C	54.5
// D	44.5
// E	34.5
// U	0
    // 1 C* level
    // 1 C level
    // 1 D level
    // 1 E level

    // 2024-2025 AS grade boundaries
    int Acut = 80 ;
    int Bcut = 68 ;
    int Ccut = 55 ;
    int Dcut = 45 ;
    int Ecut = 35 ;

    int Homeworkcut=70 ;




    //input variables to build report first line
    std::string group,name,surename,sex,homework,attendance;
    std::string T1,T2,T3,T4,T5,PRACTICAL,marks,grade,A,B,C,D,E,predicted,tes1,tes2,tes3,home1,home2;
    
    unsigned int ClassMarkAve, ClassMarkDIS ;
    unsigned int ClassMarkMAX,ClassMarkMIN ;
    float ClassMarkSTD ;
    
    
    int sus;
    int Q1,Q2,Q3,Q4,Q5,PRAC,mark;
    int homework1,homework2,test1,test2,test3;
    

    // Skiping very first line
    getline(InputFile, line);

    // reading first line to get the topics
    getline(InputFile, line);
    std::stringstream aa(line);
    aa >> group >> surename >> name >> sex >> T1 >> T2 >> T3 >> T4 >> T5 >> PRACTICAL >> marks >> grade >> predicted >> tes1 >> tes2 >> tes3  ; 

    cout << "File headers" << endl ;

    // Reading the data for each pupil
    cout << YELLOW << group << " " << surename << " " << name << " " << sex << " " << T1 << " " << T2 << " " << T3 << " " << T4 << " " << T5 << " " << PRACTICAL << " " << tes1 << " " << tes2 << " "  << tes3 << RESET << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    
    
   

    
    
    while (getline(InputFile, line))
    {
        std::stringstream aa(line) ;
        aa >> group >> surename >> name >> sex >> Q1 >> Q2 >> Q3 >> Q4 >> Q5 >> PRAC >> mark >> grade >> predicted >> test1 >> test2  >> test3 ; //>> homework1 >> homework2


 

    // Checks correct input
    // cout << YELLOW << group << " " << surename << " " << name << " " << sex << " " << Q1 << " " << Q2 << " " << Q3 << " " << Q4 << " " << Q5 << " " << Q6 << " " << marks << " " << grade << " " << predicted << " " << test1 << " " << test2 " " << test3 <<  RESET << endl ;
    
           
        // Data analysis sex to number
            
            if (sex == "M") {sus = 1;}
            if (sex == "F") {sus = 0;}

        // Synonyms random association
            
            choicesa6 = rand() % 6;
            choicesb6 = rand() % 6;
            choicesc6 = rand() % 6;
            choicesd6 = rand() % 6;
            
            choicesa5 = rand() % 5;
            choicesb5 = rand() % 5;
            choicesc5 = rand() % 5;
            choicesd5 = rand() % 5;
            
            choicesa4 = rand() % 4;
            choicesb4 = rand() % 4;
            choicesc4 = rand() % 4;
            choicesd4 = rand() % 4;
            
            choicesa3 = rand() % 3;
            choicesb3 = rand() % 3;
            choicesc3 = rand() % 3;
            choicesd3 = rand() % 3;
            
            choicesa2 = rand() % 2;
            choicesb2 = rand() % 2;
            choicesc2 = rand() % 2;
            choicesd2 = rand() % 2;
            


        //-------------------------------
        // Class test average
        //-------------------------------

        std::vector<int> ClassTest;

        ClassTest.push_back (test1) ;
        ClassTest.push_back (test2) ;
        ClassTest.push_back (test3) ;
        // ClassTest.push_back (test4) ;
        // ClassTest.push_back (test5) ;
        // ClassTest.push_back (test6) ;
        


        int MissedTest=0;

        for (int i = 0; i < 3; i++) {if( ClassTest[i] == 0 ){MissedTest++ ;}}

        // cout << "Miss tests=" << MissedTest++ << endl ;

        // In case someone miss 1 exam
        ClassMarkAve= (test1 + test2 + test3)/(3-MissedTest);


        // cout << YELLOW << group << "Class test average: " << ClassMarkAve << RESET << endl ;
        

        //--------------------------------------------------------------------------------------
        // Class test dispersion definition (standard deviation does not work for small samples)
        //--------------------------------------------------------------------------------------



        int ClassMarkMAX;
        int ClassMarkMIN;

        ClassMarkMAX = std::max({test1, test2, test3});
        ClassMarkMIN = std::min({test1, test2, test3});

        // In case someone miss an exam...
        if ( test1 == 0 )
        {
            ClassMarkMAX = std::max({test2,test3});
            ClassMarkMIN = std::min({test2,test3});
        }
        if ( test2 == 0 )
        {
            ClassMarkMAX = std::max({test1,test3});
            ClassMarkMIN = std::min({test1,test3});
        }
        if ( test3 == 0 )
        {
            ClassMarkMAX = std::max({test1,test2});
            ClassMarkMIN = std::min({test1,test2});
        }
        // if ( test4 == 0 )
        // {
        //     ClassMarkMAX = std::max({test1,test2,test3});
        //     ClassMarkMIN = std::min({test1,test2,test3});
        // }
        // if ( test5 == 0 )
        // {
        //     ClassMarkMAX = std::max({test1,test2,test3, test4,test6});
        //     ClassMarkMIN = std::min({test1,test2,test3, test4,test6});
        // }
        // if ( test6 == 0 )
        // {
        //     ClassMarkMAX = std::max({test1,test2,test3, test4,test5});
        //     ClassMarkMIN = std::min({test1,test2,test3, test4,test5});
        // }



 
        
        // std::cout << "max class test=" << ClassMarkMAX << "\n";
        // std::cout << "min clas test =" << ClassMarkMIN << "\n";

        ClassMarkDIS = ClassMarkMAX-ClassMarkMIN ;

        // cout << YELLOW << group << "Class test dispersion (dis): " << ClassMarkDIS << RESET << endl ;


            
            
 
            
            //-----------------
            // Topics to revise
            //-----------------

            std::string ToRevise;

            int CountTopics ;

            CountTopics = 0 ;
            
            
            if ( Q1 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T1 ;
                tmp >> ToRevise;
                CountTopics++ ;
            }
            
            if ( Q2 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T2 ;
                tmp >> ToRevise ;
               CountTopics++ ;
            }
            
            if ( Q3 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T3 ;
                tmp >> ToRevise ;
               CountTopics++ ;
            }
            
            if ( Q4 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T4 ;
                tmp >> ToRevise ;
               CountTopics++ ;
            }
            
            if ( Q5 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T5 ;
                tmp >> ToRevise ;
               CountTopics++ ;
            }
            
            if ( PRAC < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << PRACTICAL ;
                tmp >> ToRevise ;
                CountTopics++ ;
            }
            
            // if ( Q7 < 65 ){
            //     std::stringstream tmp ;
            //     tmp << ToRevise << T7  ;
            //     tmp >> ToRevise;
            //    CountTopics++;
            // }

            // if ( Q8 < 65 ){
            //     std::stringstream tmp ;
            //     tmp << ToRevise << T8  ;
            //     tmp >> ToRevise;
            //    CountTopics++;
            // }

            // if ( Q9 < 65 ){
            //     std::stringstream tmp ;
            //     tmp << ToRevise << T9  ;
            //     tmp >> ToRevise;
            //    CountTopics++;
            // }

            // if ( Q10 < 65 ){
            //     std::stringstream tmp ;
            //     tmp << ToRevise << T10  ;
            //     tmp >> ToRevise;
            //    CountTopics++;
            // }

            // if ( Q11 < 65 ){
            //     std::stringstream tmp ;
            //     tmp << ToRevise << T11  ;
            //     tmp >> ToRevise;
            //    CountTopics++;
            // }
            
           // cout << name <<" should revise " << CountTopics << " topics" <<endl;
//            cout << name <<" should revise " << ToRevise << " length" << ToRevise.length()<< endl ;
            
            
            
            
            // If CountTopics=1 topic singular
            // If CountTopics>1 topics plural
            if ( CountTopics == 1 ){toto = 0; }
            if ( CountTopics > 1 ){toto = 1; }

            if ( CountTopics <= 10 ){alltopics = 0; }
            if ( CountTopics > 10 ){alltopics = 1; }


            // int HomeworkAve;
            // int HomeworkLack = 0; // needs initiallise
            // Homework checker
            // quality:
            // HomeworkAve = ( homework1 + homework2 )/2;
            // Missing
            // if ( homework1 == 0 ){HomeworkLack = 1;}
            // if ( homework2 == 0 ){HomeworkLack = 1;}
            // if ( homework3 == 0 ){HomeworkLack = 1;}
            // if ( homework4 == 0 ){HomeworkLack = 1;}

            



            // define a variable to count the number of homework missing
            // we need to define homework vector

        //     std::vector<int> HomeWorkvec;

        // HomeWorkvec.push_back (homework1) ;
        // HomeWorkvec.push_back (homework2) ;
        // HomeWorkvec.push_back (homework3) ;
        // HomeWorkvec.push_back (homework4) ;
        // HomeWorkvec.push_back (homework5) ;
        // HomeWorkvec.push_back (homework6) ;
        // HomeWorkvec.push_back (homework7) ;
        
        
        // int MissedHomework=0;
        // for (int i = 0; i < 7; i++) {if( HomeWorkvec[i] == 0 ){MissedHomework++ ;}}






            //--------------------------------------------------------------
            // Heading line out to have a reference before report is written
            //--------------------------------------------------------------
            cout << endl ;
            cout << endl ;
            cout << endl ;
            cout << name << " " << surename << " " << group << endl ;
            cout << "(Mark= " << mark << "  Grade " << grade << " class min " << ClassMarkMIN << " class max " << ClassMarkMAX << " Class ave: " << ClassMarkAve << " Class dis: " << ClassMarkDIS << " to revise: " << CountTopics << " topics)" << endl ;
            cout << endl ;
            




// ADD how grade was calculated. (80% + 20%)

    // *****************************
    // A grade starts here
    // *****************************
            
    if ( mark >= Acut )
    {
        cout << name << " " << Achi[choicesa3] << " " << Excellence[choicesa3] << " result in " << hisher[sus] << " Winter examination.  " ;
        cout << "The grade was determined by a weighted average of the examination components, with 80\% from the theory section and 20\% from the practical section.  " ;
        cout << Cheshe[sus] << " adapted exceptionally well to the rigorous demands of A-level studies.  " ;

        // A* performance
        if ( ClassMarkAve >= 90 )
        {
            cout << Cheshe[sus] << " maintained " << Excellence[choicesb2] << " high standard throughout the term.  " << Cheshe[sus]  << " is a highly capable pupil and grasps new physical concepts with ease.  " << Cheshe[sus]  << " can select and apply equations " << AsRequired[choicesa5] << ".  " ;

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                cout << "To secure " << hisher[sus] << " A level performance " ;

                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all the topics covered so far is strongly recommended.  " ;
                    }   
                cout << endl ; 
                cout << endl ; 
            }
            else
            {
                cout << "Well done " << name << "!" << endl ;
                cout << endl ; 
                cout << endl ; 
            }

        }


        // A performance
        if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
        {
            cout << Cheshe[sus] << " maintained " << Excellence[choicesb2] << " and consistent standard throughout the term.  " << Cheshe[sus]  << " is a highly capable pupil and grasps new physical concepts with ease.  " << Cheshe[sus]  << " can select and apply equations " << AsRequired[choicesa5] << ".  " ;



            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                cout << "To secure " << hisher[sus] << " A level performance " ;

                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is recommended.  " ;
                    } 
                cout << endl ; 
                cout << endl ; 
            }
            else
            {
            cout << "Well done " << name << "!" << endl ;
            cout << endl ; 
            cout << endl ; 
            }

        }


        // B performance
        if ( 80 > ClassMarkAve && ClassMarkAve >= 70 )
        {
            if ( ClassMarkDIS <= 25 )
            {
                cout << Cheshe[sus] << " maintained a consistent good standard throughout the term.  However, to ensure " << hisher[sus] << " A level performance, " << heshe[sus] << " must raise the standard of " << hisher[sus] << " daily work.  " ;
            }
            if ( ClassMarkDIS > 25 )
            {
                cout << Cheshe[sus] << " maintained a pleasing but irregular standard throughout the term.  To ensure " << hisher[sus] << " A level performance, " << heshe[sus] << " must raise the standard of " << hisher[sus] << " daily work.  " ;
            }  

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                cout << "To accomplish that " << heshe[sus] << " needs regular independent study.  " ;

                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is recommended.  " ;
                    }   

                cout << endl ; 
                cout << endl ; 
            }
            else
            {
                cout << "Well done " << name << "!" << endl ;
                cout << endl ; 
                cout << endl ; 
            }

        }



            // C* Performance  (Improved with respect to section C* for A* HIGH AND LOW grade check )
            
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 )
            {
                if ( ClassMarkDIS <= 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was consistently well below this grade.  Improving the standard of " << hisher[sus] << " daily work is essential to ensure success in his A level Physics.  " ;
                                                                                    // class standard was consistently significantly below          
                }                                                                                                                                  //Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.

                if ( ClassMarkDIS > 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was irregular and well below this grade.  Improving the standard of " << hisher[sus] << " daily work is essential to ensure success in his A level Physics.  " ;
                }   

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}                                                                                                                                     

                if ( CountTopics != 0 )
                {

                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
                cout << endl ; 
                cout << endl ; 
                }
                else
                {
                cout << "Well done " << name << "!" << endl ;
                cout << endl ; 
                cout << endl ; 
                }

            }


            // C Performance
            if ( 60 > ClassMarkAve && ClassMarkAve >= 50 )
            {
                 if ( ClassMarkDIS <= 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was consistently well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }

                if ( ClassMarkDIS > 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was irregular and well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }     


            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

                if ( CountTopics != 0 )
                {
                cout << " To accomplish that " << heshe[sus] << " must plan and execute " << hisher[sus] << " study and homework weekly.  " ;

                
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
                cout << endl ; 
                cout << endl ; 
                }
                else
                {
                cout << "Well done " << name << "!" << endl ;
                cout << endl ; 
                cout << endl ; 
                }

            }
        

    
            if ( 50 > ClassMarkAve )
            {
                 if ( ClassMarkDIS <= 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was consistently well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }

                if ( ClassMarkDIS > 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was inconsistent and well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }     

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

                if ( CountTopics != 0 )
                {

                cout << Cheshe[sus] << " must plan and execute " << hisher[sus] << " study and homework weekly.  " ;

                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
                
                cout << endl ; 
                cout << endl ; 
                }
                else
                {
                cout << "Well done " << name << "!" << endl ;
                cout << endl ; 
                cout << endl ; 
                }

            }

    }// End of  A grade

    // *****************************
    // B grade starts here
    // *****************************
      
    if ( mark < Acut && mark >= Bcut )
    {
        cout << name << " " << Achi[choicesa3] << " " << MediumHigh[choicesa3] << " result in " << hisher[sus] << " Winter examination.  " ;
        cout << "The grade was determined by a weighted average of the examination components, with 80\% from the theory section and 20\% from the practical section.  " ;
        cout << Cheshe[sus] << " is steadily adapting to the rigorous demands of A-level studies.  " ;


        // A* performance
        if ( ClassMarkAve >= 90 )
        {
            cout << Cheshe[sus] << " has maintained an extraordinarily high level of excellence throughout the term.  Despite this, " << hisher[sus] << " Winter examination results did not reflect " << hisher[sus] << " hard work and dedication.  ";

                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all the topics covered so far is strongly recommended.  " ;
                    }   
                cout << endl ; 
                cout << endl ; 
        }
        else
        {
                cout << "Well done " << name << "!" << endl ;
                cout << endl ; 
                cout << endl ; 
        }

            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has responded positively to the demands of the subject maintaining consistently a good standard throughout the term.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has responded positively to the demands of the subject maintaining an irregular good standard throughout the term.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a consistent and pleasing standard throughout the term.  " << Chisher[sus]  << " steady progression has been reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has continued to perform at an irregular but rising standard throughout the term.  " << Chisher[sus] << " progression has been reflected in " << hisher[sus] << " Winter examination.  " ;
            }
            
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were consistently low throughout the term, " << heshe[sus]  << " improved " << hisher[sus] << " standard for the Winter examination.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were irregular and low throughout the term, " << heshe[sus]  << " improved " << hisher[sus] << " standard for the Winter examination.  " ;
            }
            

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                cout << "To do even better, ";

                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is important to consolidate " << hisher[sus] << " knowledge.  " ;
                    }   
            cout << endl ; 
            cout << endl ; 
            }
            else
            {
            cout << "Well done " << name << "!" << endl ; 
            cout << endl ; 
            cout << endl ; 
            }

    }// End of  B grade


    // *****************************
    // C grade starts here
    // *****************************

    if ( mark < Bcut && mark >= Ccut )
    {
                cout << name << " " << Achi[choicesa3] << " " << MediumLow[choicesb3] << " result in " << hisher[sus] << " Winter examination.  " ;
                cout << "The grade was determined by a weighted average of the examination components, with 80\% from the theory section and 20\% from the practical section.  " ;
                cout << Cheshe[sus] << " is progressively adapting to the demands of A-level studies but finds them challenging.  " ;
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, surprisingly this was not reflected in " << hisher[sus] << " Winter examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }


            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }
            
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a good and consistent standard throughout the term, which has been reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained a good but slightly irregular standard throughout the term, which has been reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << " However, " << hisher[sus] << " class performance was consistently poor.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << " However, " << hisher[sus] << " class performance was irregular and poor.  " ;
            }

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                cout << "To progress, ";
                
                if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all GCSE physics topics covered so far should be made.  " ;
                    }   
                cout << endl ; 
                cout << endl ; 
            }
                else
            {
                cout << "Well done " << name << "!" << endl ; 
                cout << endl ; 
                cout << endl ; 
            }

    }// End of C grade
        
        

    // *****************************
    // D grade starts here
    // *****************************
          
    // surprisingly incomprehensibly perplexingly paradoxically
            

    if ( mark < Ccut && mark >= Dcut )
    {
        cout << name << " obtained " << Badness[choicesb3] << " result in " << hisher[sus] << " Winter examination.  " ;
        cout << "The grade was determined by a weighted average of the examination components, with 80\% from the theory section and 20\% from the practical section.  " ;
        cout << Cheshe[sus] << " is struggling to adapt to the demands of A-level Physics.  " ;
        

            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, surprisingly this was not reflected in " << hisher[sus] << " Winter examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, incomprehensibly this was not reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a fair and consistent standard throughout the term,  unfortunately " << heshe[sus] << " underperformed in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained an inconsistent standard throughout the term.  " ;
            }
        
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << Chisher[sus] << " performance was consistently poor throughout the term.  " << heshe[sus] << " is compromising " << hisher[sus] << " potential through lack of effort.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << Chisher[sus] << " performance was inconsistent and poor throughout the term.  " ;
            }

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                cout << "To progress, a much more committed approach is necessary.  ";

                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all GCSE physics topics covered so far is recommended.  " ;
                    }   
            cout << endl ; 
            cout << endl ; 
            }
    }// End of D grade


    // *****************************
    // E grade starts here
    // *****************************

    
    if ( mark < Dcut )
    {
        cout << name << " obtained " << Badness[choicesb3] << " result in " << hisher[sus] << " Winter examination.  " ;
        cout << "The grade was determined by a weighted average of the examination components, with 80\% from the theory section and 20\% from the practical section.  " ;
        cout << Cheshe[sus] << " is finding it particularly difficult to meet the demands of A-level Physics.  " ;
        
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, surprisingly this was not reflected in " << hisher[sus] << " Winter examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, incomprehensibly this was not reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly iinconsistent standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Winter examination.  " ;
            }
        
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a fair and consistent standard throughout the term,  unfortunately " << heshe[sus] << " underperformed in " << hisher[sus] << " Winter examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained an inconsistent standard throughout the term.  " ;
            }
           
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << Chisher[sus] << " performance was consistently below expectations throughout the term.  " << heshe[sus] << " is compromising " << hisher[sus] << " potential through lack of effort.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << Chisher[sus] << " performance was inconsistent and poor throughout the term.  " ;
            }

            if ( PRAC > 85 ){cout << Chisher[sus] << " practical work demonstrates exceptional skills in analysis and evaluation.  " ;}
            if ( 85 >= PRAC > 70 ){cout << Chisher[sus] << " practical work shows skill in analysis and evaluation.  " ;}
            if ( 70 >= PRAC  ){cout << Cheshe[sus] << " must improve " << hisher[sus] << " practical skills and data analysis.  " ;}

            if ( CountTopics != 0 )
            {
                    if (alltopics == 0)
                    {
                    cout << "A thorough review of " << hisher[sus] << " study methods is necessary.  " << Cheshe[sus] << " should create a structured routine, focus on key concepts, seek extra help, and practise past papers regularly to address weaknesses and improve.  " ;
                    cout << "In particular, " << heshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << "." ; 
                    }
                    else
                    {
                    cout << "A thorough review of " << hisher[sus] << " study methods is necessary.  " << Cheshe[sus] << " should create a structured routine, focus on key concepts, seek extra help, and practise past papers regularly to address weaknesses and improve." ;
                    }   
            }
            cout << endl ; 
            cout << endl ; 

    } // End of E grade




    } // While reading line finish here



    InputFile.close() ;

    return (0) ;
}


// Be careful not to over-schedule your child with extracurricular activities.  Establish homework times and a routine.
// https://health.clevelandclinic.org/8-tips-for-talking-about-bad-grades/








 