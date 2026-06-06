// COMPILATION: g++ -std=c++11 F4-SUMMER-2026.cpp
// USE ./a.out [data]
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
    std::cout << BOLDYELLOW << "          /__/  \\         Carles Triguero 2026      " << RESET << std::endl ;
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
    
    
    
        // Files to store data
        ofstream Reports ;
        Reports.open ("Reports.txt", ios::out | ios::trunc); // Report file to copy and paste on sims
    
    
    
    
    
    
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
    int toto, alltopics;
    
    // MedLow modest,

    
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
    
// A	70
// B	60
// C*53
// C	45
// D	38
// E	0

//  Summer 2026 grade boundaries
    // int AXcut = 100 ;
    int Acut = 70 ;
    int Bcut = 60 ;
    int CXcut = 53 ;
    int Ccut = 45 ;
    int Dcut = 38 ;
    int Ecut = 0 ;

    int Homeworkcut=70 ;
    
    // int AXM ;
    // AXM=100-(100-AXcut)/2;



    //Fields as strings input variables to build report first line
    std::string group,name,surename,sex,homework,attendance;
    std::string T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,marks,grade,A,B,C,D,E,predicted;
    std::string tes1,tes2,tes3,tes4,tes5,home1,home2;
    
    unsigned int ClassMarkAve, ClassMarkDIS ;
    unsigned int ClassMarkMAX,ClassMarkMIN ;
    float ClassMarkSTD ;
    
    int sus;
    int Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Q9,Q10,Q11,mark;
    int homework1,homework2,test1,test2,test3,test4,test5;
    

//  Data reading

//  Skiping very first line
    getline(InputFile, line);

//  Reading first line to get the topics WORDS (fields)
    getline(InputFile, line);
    std::stringstream aa(line);
    aa >> group >> surename >> name >> sex >> T1 >> T2 >> T3 >> T4 >> T5 >> T6 >> T7 >> T8 >> mark >> grade >> predicted >> tes1 >> tes2 >> tes3 >> tes4 >> tes5 ;

    cout << "File headers" << endl ;

    // Reading the data for each pupil
    cout << YELLOW << group << " " << surename << " " << name << " " << sex << " " << T1 << " " << T2 << " " << T3 << " " << T4 << " " << T5 << " " << T6 << " " << T7 << " " << T8 << " " << T9 << " " << T10 << " " << mark << " " << grade << " " << predicted << " " << tes1 << " " << tes2 << " " << tes3 << " " << tes4 << " " << tes5 << RESET << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    


// Reads line by line numerical values for each field
while (getline(InputFile, line))
{
    std::stringstream aa(line) ;
    aa >> group >> surename >> name >> sex >> Q1 >> Q2 >> Q3 >> Q4 >> Q5 >> Q6 >> Q7 >> Q8 >> mark >> grade >> predicted >> test1 >> test2 >> test3 >> test4 >> test5;

        // Checks correct input
        // cout << YELLOW << group << " " << surename << " " << name << " " << sex << " " << Q1 << " " << Q2 << " " << Q3 << " " << Q4 << " " << Q5 << " " << Q6 << " " << Q7 << " " << Q8 << " " << Q9 << " " << Q10 << " " << marks << " " << grade << " " << predicted << " " << test1 << " " << test2 << " " << homework1 << " " << homework2 << RESET << endl ;
    
           
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
        ClassTest.push_back (test4) ;
        ClassTest.push_back (test5) ;
        // ClassTest.push_back (test6) ;
        
        int MissedTest = 0;

        for (int i = 0; i < 5; i++) {if( ClassTest[i] == 0 ){MissedTest++ ;}}

        // cout << "Miss tests=" << MissedTest++ << endl ;

        // In case someone miss 1 or more class tests
        ClassMarkAve= (test1 + test2 + test3 + test4 + test5)/(5-MissedTest);


        // cout << YELLOW << group << "Class test average: " << ClassMarkAve << RESET << endl ;
        
        //--------------------------------------------------------------------------------------
        // Class test dispersion definition (standard deviation does not work for small samples)
        //--------------------------------------------------------------------------------------

        int ClassMarkMAX;
        int ClassMarkMIN;

        ClassMarkMAX = std::max({test1, test2, test3, test4, test5});
        ClassMarkMIN = std::min({test1, test2, test3, test4, test5});

        // In case someone miss one exam...
        if ( test1 == 0 )
        {
            ClassMarkMAX = std::max({test2, test3, test4, test5});
            ClassMarkMIN = std::max({test2, test3, test4, test5});
        }
        if ( test2 == 0 )
        {
            ClassMarkMAX = std::max({test1, test3, test4, test5});
            ClassMarkMIN = std::max({test1, test3, test4, test5});
        }
        if ( test3 == 0 )
        {
            ClassMarkMAX = std::max({test1, test2, test4, test5});
            ClassMarkMIN = std::max({test1, test2, test4, test5});
        }
        if ( test4 == 0 )
        {
            ClassMarkMAX = std::max({test1, test2, test3, test5});
            ClassMarkMIN = std::max({test1, test2, test3, test5});
        }
        if ( test5 == 0 )
        {
            ClassMarkMAX = std::max({test1, test2, test3, test4});
            ClassMarkMIN = std::max({test1, test2, test3, test4});
        }
        

        
        // std::cout << "max class test=" << ClassMarkMAX << "\n";
        // std::cout << "min clas test =" << ClassMarkMIN << "\n";

        ClassMarkDIS = ClassMarkMAX - ClassMarkMIN ;

        // cout << YELLOW << group << "Class test dispersion (dis): " << ClassMarkDIS << RESET << endl ;






// TREND CALCULATOR fitting class test to see if there is a progression to better equal or bad






        //-----------------
        // Topics to revise weak results by components
        //-----------------

            std::string ToRevise;
            int CountTopics;
            CountTopics = 0;
            
            
            if ( Q1 < 65 ){
                std::stringstream tmp;
                tmp << ToRevise << T1 ;
                tmp >> ToRevise;
                CountTopics++;
            }
            
            if ( Q2 < 65 ){
                std::stringstream tmp;
                tmp << ToRevise << T2  ;
                tmp >> ToRevise;
               CountTopics++;
            }
            
            if ( Q3 < 65 ){
                std::stringstream tmp;
                tmp << ToRevise << T3  ;
                tmp >> ToRevise;
               CountTopics++;
            }
            
            if ( Q4 < 65 ){
                std::stringstream tmp;
                tmp << ToRevise << T4  ;
                tmp >> ToRevise;
               CountTopics++;
            }
            
            if ( Q5 < 65 ){
                std::stringstream tmp;
                tmp << ToRevise << T5  ;
                tmp >> ToRevise;
               CountTopics++;
            }
            
            if ( Q6 < 65 ){
                std::stringstream tmp;
                tmp << ToRevise << T6  ;
                tmp >> ToRevise;
                CountTopics++;
            }
            
            if ( Q7 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T7  ;
                tmp >> ToRevise;
               CountTopics++;
            }

            if ( Q8 < 65 ){
                std::stringstream tmp ;
                tmp << ToRevise << T8  ;
                tmp >> ToRevise;
               CountTopics++;
            }

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
            
            
            
            
            // If CountTopics=1 topic singular (Just one topic to revise)
            // If CountTopics>1 topics plural (More than one topic to revise)
            // This states if is singular numbr or plural number of topics to determine article
            if ( CountTopics == 1 ){toto = 0; }
            if ( CountTopics > 1 ){toto = 1; }

            // Only up to 4 topics are listed if there are more than 4 full revision recomended.
            if ( CountTopics <= 4 ){alltopics = 0; }
            if ( CountTopics > 4 ){alltopics = 1; }



// HOMEWORK NOT CONSIDERED

            // We do not consider homework in 2026
            int HomeworkAve = 100;
            int HomeworkLack = 0; // needs initiallise
            // Homework checker
            // quality:
            // HomeworkAve = ( homework1 + homework2 )/2;
            // // Missing
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
        
        
        int MissedHomework=0;
        // for (int i = 0; i < 7; i++) {if( HomeWorkvec[i] == 0 ){MissedHomework++ ;}}





            //--------------------------------------------------------------
            // Heading line out to have a summary reference before report is written
            //--------------------------------------------------------------
            cout << endl ;
            cout << endl ;
            cout << endl ;
            cout << name << " " << surename << " " << group << endl ;
            cout << "(Mark= " << mark << "  Grade " << grade << " class min " << ClassMarkMIN << " class max " << ClassMarkMAX << " Class ave: " << ClassMarkAve << " Class dis: " << ClassMarkDIS << " Homework ave: " << HomeworkAve  << " Homework lack: " << HomeworkLack << " Homework missed: " << MissedHomework << " to revise: " << CountTopics << " topics)" << endl ;
            cout << endl ;
            

           
            
            //            a natural consequence of her ability and hard work.
            //            a natural result of her talent and hard work.
            //            a natural outcome of her capacity and hard work.
            //            logical outcome

            
            
//            For further consolidation of hiher knowledge, heshe should review all the topics covered in this course in detail.
            
            // His knowledge should be reinforced by reviewing all topics covered in this course in detail.
            
            // In order to consolidate the skills heshe learned this course, he should review all the topics covered in detail.
            
            // He should review all the topics studied in this course thoroughly to ensure he has retained what heshe has learned
            








    // if ( predicted == "no")
    // {





           





            // *****************************
            // A grade starts here
            // *****************************

            
    if ( mark >= Acut )
    {
        cout << name << " " << Achi[choicesa3] << " " << Excellence[choicesa3] << " result in " << hisher[sus] << " Summer examination.  " ;


        // Year performance based on class averages and dispersion and homework average




        // A* performance
        if ( ClassMarkAve >= 90 )
        {
        // cout << "profile A1" << endl ; 


            cout << Cheshe[sus] << " maintained " << Excellence[choicesb2] << " high standard throughout the term.  " << Cheshe[sus]  << " is a highly capable pupil and grasps new physical concepts with ease.  " << Cheshe[sus]  << " can select and apply equations " << AsRequired[choicesa5] << ".  " ;


            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To secure " << hisher[sus] << " GCSE performance " ;

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << heshe[sus] << " should improve the quality of " << hisher[sus] << " homework.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << heshe[sus] << " should complete all homework and raise its quality.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework to " << hisher[sus] << " higher standard.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
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
           // cout << "profile A2" << endl ; 

            cout << Cheshe[sus] << " maintained " << Excellence[choicesb2] << " and consistent standard throughout the term.  " << Cheshe[sus]  << " is a highly capable pupil and grasps new physical concepts with ease.  " << Cheshe[sus]  << " can select and apply equations " << AsRequired[choicesa5] << ".  " ;


            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To secure " << hisher[sus] << " GCSE performance " ;

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << heshe[sus] << " should improve the quality of " << hisher[sus] << " homework.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework to " << hisher[sus] << " higher standard.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                // cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework.  ";
                cout << heshe[sus] << "should complete all homework.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is recommended.  " ;
                    }   
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
        // Idem dispersion or not
        if ( 80 > ClassMarkAve && ClassMarkAve >= 70 )
        {
            //cout << "profile A3" << endl ; 

            if ( ClassMarkDIS <= 25 )
            {
                cout << Cheshe[sus] << " maintained a consistent good standard throughout the term.  However, to ensure " << hisher[sus] << " GCSE performance, " << heshe[sus] << " must raise the standard of " << hisher[sus] << " daily work.  " ;
            }
            if ( ClassMarkDIS > 25 )
            {
                cout << Cheshe[sus] << " maintained a pleasing but irregular standard throughout the term.  To ensure " << hisher[sus] << " GCSE performance, " << heshe[sus] << " must raise the standard of " << hisher[sus] << " daily work.  " ;
            }   //Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;

            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To accomplish that " << heshe[sus] << " needs regular independent study.  " ;

                // Bad quality homework
                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                { // It is important that all homework is completed in a timely manner and to a high standard of quality.
                cout << Cheshe[sus] << " should improve the quality of " << hisher[sus] << " homework.  " ;
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework to " << hisher[sus] << " higher standard.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << " should complete all homework.  " ;
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is recommended.  " ;
                    }   
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
        // Idem dispersion or not




// AI generated about homework
// It is important that all homework is completed in a timely manner and to a high standard of quality. Doing so will help to ensure that students gain the most out of their studies and can progress to the next level of their education. To complete homework and improve its quality, it is important to plan in advance and set aside enough time for the task. Additionally, it is important to research the topic thoroughly in order to get the most out of it and use resources such as online tutorials, textbooks, and lectures to help. Finally, it is important to review the work and make sure it meets the expectations of the assignment and is to the standard required. By taking these steps, students can ensure their homework is completed to a high quality and on time.
// AI generated about pleasing but irregular performance
// She consistently demonstrated a level of excellence throughout the year, though her performance was not always consistent. In some months she would reach a higher standard than in others, but her overall commitment to excellence was still evident. She pushed herself to be the best she could be in every situation, and her dedication to success was clear. Despite occasional dips in her performance, she maintained a pleasing standard of quality and effort throughout the year.
// Surprisingly, his class standard was far from consistent, and he was performing significantly below his expected grade. His grades were lower than what could have been expected from him, and it was clear that his efforts were not meeting the expectations of the course. The discrepancy between his expected performance and his actual performance was significant, and it was becoming increasingly clear that he was not able to keep up with the class standards. It is difficult to pinpoint the exact cause of this irregular performance, however it was clear that his efforts were not sufficient to help him reach the standard expected of him.
// However, despite his grade, his class standard was highly irregular and significantly below.
//  raising the standard of daily work is essential in order to ensure success in GCSEs. A student should be dedicating time to their studies, making sure they are understanding the material, and keeping track of their progress. By taking these steps, a student will be able to ensure their GCSE performance is up to a high standard.

            // C* Performance  (Improved with respect to section C* for A* HIGH AND LOW grade check )
            // Idem dispersion or not

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 )
            {

              //  cout << "profile A4" << endl ; 

                if ( ClassMarkDIS <= 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was consistently well below this grade.  Improving the standard of " << hisher[sus] << " daily work is essential to ensure success in his GCSE.  " ;
                                                                                    // class standard was consistently significantly below          
                }                                                                                                                                  //Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.

                if ( ClassMarkDIS > 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was irregular and well below this grade.  Improving the standard of " << hisher[sus] << " daily work is essential to ensure success in his GCSE.  " ;
                }                                                                                                                                        

                // Any of this conditions or one or other or etc activates room for improvement

                if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
                {

                // cout << "To accomplish that " << heshe[sus] << " needs regular independent study.  " ;

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << Cheshe[sus] << "should focus on raising the quality of " << hisher[sus] << " homework.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework to " << hisher[sus] << " higher standard.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all of " << hisher[sus] << " homework.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
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
            // Idem dispersion or not





            // C Performance
            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkAve >= 50 )
            {
               // cout << "profile A5" << endl ; 

                 if ( ClassMarkDIS <= 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was consistently well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }

                if ( ClassMarkDIS > 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was irregular and well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }     

                // Any of this conditions or one or other or etc activates room for improvement

                if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
                {

                cout << " To accomplish that " << heshe[sus] << " must plan and execute " << hisher[sus] << " study and homework weekly.  " ;

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << Cheshe[sus] << "should improve the quality of " << hisher[sus] << " homework.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework to " << hisher[sus] << " higher standard.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all of " << hisher[sus] << " homework.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
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
            // Idem dispersion or not
        



            // D Performance
            // Idem dispersion or not
            if ( 50 > ClassMarkAve )
            {

               // cout << "profile A6" << endl ; 

                 if ( ClassMarkDIS <= 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was consistently well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }

                if ( ClassMarkDIS > 25 )
                {
                cout << "Despite " << hisher[sus] << " high grade, " << hisher[sus] << " class standard was inconsistent and well below this grade.  Raising " << hisher[sus] << " standard of daily work is essential in order to ensure success in GCSE.  " ;
                }     

                // Any of this conditions or one or other or etc activates room for improvement

                if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
                {

                //cout << "To accomplish that " << heshe[sus] << " must plan and execute " << hisher[sus] << " study and homework weekly.  " ;
                cout << Cheshe[sus] << " must plan and execute " << hisher[sus] << " study and homework weekly.  " ;

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << Cheshe[sus] << " should improve the quality of " << hisher[sus] << " homework.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << " should complete all homework and raise its quality.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << " should complete all homework.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
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
            // Idem dispersion or not




    }// End of  A grade

            



















// //             //class marks were irregular and lower throughout the year.
// //             //Class assesment result were irregular and lower throughout the year. 
            




            //*****************************
            // B grade starts here (no so bad)
            //*****************************


            
            if ( mark < Acut && mark >= Bcut )
            {
                cout << name << " " << Achi[choicesa3] << " " << MediumHigh[choicesa3] << " result in " << hisher[sus] << " Summer examination.  " ;

            // Year performance based on class averages and dispersion and homework average
            

            // A* performance
            if ( ClassMarkAve >= 90 )
            {
            // cout << "profile B1" << endl ; 

            cout << Cheshe[sus] << " has maintained an extraordinarily high level of excellence throughout the term.  Despite this, " << hisher[sus] << " Summer examination results did not reflect " << hisher[sus] << " hard work and dedication.  ";
            // cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year, unfortunately this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            //Through the course of the year, she has consistently demonstrated an extraordinarily high level of excellence in her studies. Despite this, her Summer examination results did not accurately reflect her hard work and dedication to her studies. She has worked diligently and consistently all year, and her performance was a true testament to her commitment and devotion to her academic pursuits. Despite the results of her Summer examination, she has been able to maintain an exceptional level of achievement over the course of the year. Her dedication is admirable, and she should be proud of her accomplishments.


        // SEGUIR AKI



          // Any of this conditions or one or other or etc activates room for improvement

                if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
                {

                cout << " To accomplish that " << heshe[sus] << " must plan and execute " << hisher[sus] << " study and homework weekly.  " ;

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << Cheshe[sus] << "should improve the quality of " << hisher[sus] << " homework.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework and raise its quality.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                cout << Cheshe[sus] << "should complete all homework.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << "A revision of the " << topikini[toto] << " of " << ToRevise << " is suggested.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is strongly recommended.  " ;
                    }   
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








            // A* Lower performance
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has responded positively to the demands of the subject maintaining consistently a good standard throughout the term.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has responded positively to the demands of the subject maintaining an irregular good standard throughout the term.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a consistent and pleasing standard throughout the term.  " << Chisher[sus]  << " steady progression has been reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has continued to perform at an irregular but rising standard throughout the term.  " << Chisher[sus] << " progression has been reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were consistently low throughout the term, " << heshe[sus]  << " improved " << hisher[sus] << " standard for the Summer examination.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were irregular and low throughout the term, " << heshe[sus]  << " improved " << hisher[sus] << " standard for the Summer examination.  " ;
            }
            // Idem dispersion or not



            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To do even better, ";

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }
                

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << "quality completion of all homework is fundamental.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                // cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework.  ";
                cout << "completing all homework is critical.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A thorough review of all GCSE physics topics covered so far is important to consolidate " << hisher[sus] << " knowledge.  " ;
                    }   
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


            
            
    








            //*****************************
            // C* grade starts here (the reality... bad)
            //*****************************


            if ( mark < Bcut && mark >= CXcut )
            {
                cout << name << " " << Achi[choicesa3] << " " << MediumLow[choicesb3] << " result in " << hisher[sus] << " Summer examination.  " ;

            // Year performance based on class averages and dispersion and homework average
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, surprisingly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a good and consistent standard throughout the term, which has been reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained a good but slightly irregular standard throughout the term, which has been reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << " However, " << hisher[sus] << " class performance was consistently poor.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << " However, " << hisher[sus] << " class performance was irregular and poor.  " ;
            }
            // Idem dispersion or not



            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To progress, ";

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << "quality completion of all homework is fundamental.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                // cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework.  ";
                cout << "completing all homework is very important.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all GCSE physics topics covered so far should be made.  " ;
                    }   
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
            
        



            //SEGUIR
            //*****************************
            //*****************************
            // C grade starts here
            //*****************************
            //*****************************


            if ( mark < CXcut && mark >= Ccut )
            {
                cout << name << " " << Achi[choicesa3] << " " << MediumLow[choicesb3] << " result in " << hisher[sus] << " Summer examination.  " ;

            // term performance based on class averages and dispersion and homework average
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, incomprehensibly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, perplexingly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a good but slightly irregular standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained a good and consistent standard throughout the term, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << Chisher[sus] << " performance in class was consistently below expectations.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << Chisher[sus] << " class performance was inconsistent and unsatisfactory.  " ;
            }
            // Idem dispersion or not



            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To make progress, ";

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << "the completion of homework to " << hisher[sus] <<" higher standard is essential.  "; 
                }
                // "improve the quality of " << hisher[sus] <<" homework is fundamental.  "

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << "completing all homework to " << hisher[sus] <<" higher standard is essential.  "; 
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                // cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework.  ";
                cout << "completing all homework is very important.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all GCSE physics topics covered so far is recommended.  " ;
                    }   
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





            //*****************************
            // D grade starts here (rubish)
            //*****************************

        

            // surprisingly incomprehensibly perplexingly paradoxically
            
            // failed to reflect, fails to reflect, do not correspod, not correlated

            if ( mark < Ccut && mark >= Dcut )
            {
                cout << name << " obtained " << Badness[choicesb3] << " result in " << hisher[sus] << " Summer examination.  " ;
                // instead of Achi[choicesa3] obtained
            // term performance based on class averages and dispersion and homework average
            

            // Not likely
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, surprisingly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, incomprehensibly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Not likely
            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Not likely
            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a fair and consistent standard throughout the term,  unfortunately " << heshe[sus] << " underperformed in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained an inconsistent standard throughout the term.  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << Chisher[sus] << " performance was consistently poor throughout the term.  " << heshe[sus] << " is compromising " << hisher[sus] << " potential through lack of effort.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << Chisher[sus] << " performance was inconsistent and poor throughout the term.  " ;
            }
            // Idem dispersion or not




            // Any of this conditions or one or other or etc activates room for improvement


                // if ( HomeworkAve > 70 && HomeworkLack == 0 )
                // {
                // cout << hisher[sus] << " homework was of high standard.  ";
                // }


            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To progress, a much more committed approach is necessary.  ";

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << "quality completion of all homework is fundamental.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                // cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework.  ";
                cout << "completing all homework is very important.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all GCSE physics topics covered so far is recommended.  " ;
                    }   
                }
            cout << endl ; 
            cout << endl ; 
            }

            }













            //*****************************
            // E grade starts here (horrendous)
            //*****************************


            if ( mark < Dcut )
            {
                cout << name << " obtained " << Badness[choicesb3] << " result in " << hisher[sus] << " Summer examination.  " ;
                // instead of Achi[choicesa3] obtained
            // term performance based on class averages and dispersion and homework average
            

            // Not likely
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the term, surprisingly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the term, incomprehensibly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Not likely
            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the term, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Not likely
            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a fair and consistent standard throughout the term,  unfortunately " << heshe[sus] << " underperformed in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained an inconsistent standard throughout the term.  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << Chisher[sus] << " performance was consistently poor throughout the term.  " << heshe[sus] << " is compromising " << hisher[sus] << " potential through lack of effort.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << Chisher[sus] << " performance was inconsistent and poor throughout the term.  " ;
            }
            // Idem dispersion or not




            // Any of this conditions or one or other or etc activates room for improvement


                // if ( HomeworkAve > 70 && HomeworkLack == 0 )
                // {
                // cout << hisher[sus] << " homework was of high standard.  ";
                // }


            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve <= Homeworkcut )
            {
                cout << "To progress, a much more committed approach is necessary.  ";

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve <= Homeworkcut && HomeworkLack == 1 )
                {
                cout << "quality completion of all homework is fundamental.  ";
                }

                if ( HomeworkAve > 70 && HomeworkLack == 1 )
                {
                // cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework.  ";
                cout << "completing all homework is very important.  ";
                }

                if (CountTopics != 0)
                {
                    if (alltopics == 0)
                    {
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " of " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all GCSE physics topics covered so far is recommended..  " ;
                    }   
                }
            cout << endl ; 
            cout << endl ; 
            }

            }

























            
            
        //     if ( mark < 70 && mark >= 60 )
        //     {
        //         cout << "This is " << MediumLow[choicesa2] << " mark and very well deserved.  " << name << " has maintained an exceptionally high standard throughout the term.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations in a variety of ways.  "  ;
                
        //         if (alltopics == 0)
        //         {
        //             if (CountTopics != 0){cout << " However, " << heshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate the knowledge." << endl ;}
        //             cout << endl ;
        //             cout << endl ;
        //         }
        //         else
        //         {
        //             cout << " A thorough review of all topics covered in this course is important to consolidate " << hisher[sus] << " knowledge." << endl ;
        //             cout << endl ;
        //             cout << endl ;
        //         }
        //     }
            
            
            
           
            
            
    
    
    
        //     if ( mark < 60 && mark >= 0 )
        //     {
        //         cout << endl ;
        //         cout << endl ;
        //         cout << "This is " << Badness[choicesa5] << " grade for " << name << ". "<< Cheshe[sus] <<  " found some aspects of the course " << Hard[choicesa2] << " but must continue working hard to overcome these difficulties. ";
                
        //        // While some aspects of the course are challenging, he must continue to work hard to overcome them.
                
        //         if (alltopics == 0)
        //         {
        //             if (CountTopics != 0){cout << " However, " << heshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate the knowledge." << endl ;}
        //             cout << endl ;
        //             cout << endl ;
        //         }
        //         else
        //         {
        //             cout << " A thorough review of all topics covered in this course is important to consolidate " << hisher[sus] << " knowledge." << endl ;
        //             cout << endl ;
        //             cout << endl ;
        //         }
                
        //     }
         
    // } // if predicted no







    // if ( predicted == "yes" )
    // {
    //     cout << name << " This is a predicted grade based on...  " ;
    // }











} // While reading line finish here



        InputFile.close() ;

    

    return (0) ;
}






// Be careful not to over-schedule your child with extracurricular activities.  Establish homework times and a routine.
// https://health.clevelandclinic.org/8-tips-for-talking-about-bad-grades/