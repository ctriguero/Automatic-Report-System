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
    top.push_back ("outstanding") ;
    top.push_back ("excepcional") ;
    top.push_back ("impressive") ;

    
    std::vector<std::string> Excellence;
    Excellence.push_back ("excellent") ;
    Excellence.push_back ("superb") ;
//        Excellence.push_back ("Impresive") ;
    
    
    
    std::vector<std::string> Goodness;
    Goodness.push_back ("very good") ;
    Goodness.push_back ("fabulous") ;
    Goodness.push_back ("great") ;
    Goodness.push_back ("remarcable") ;
    
    
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
    Badness.push_back ("a disapointing") ;
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

    //            A    73% or above
    //            B    56-72%
    //            C    35-55%
    //            D    34% or less
    

    //     A    73% or above
    // 3 levels
    int Acut=73;

    int AH,AM,AL;
    AH=100-(100-Acut)/3;
    AM=100-2*(100-Acut)/3;
    AL=73;
    
    cout << "A grade subgrades" << endl ;
    cout << "AH=" << AH << "   AM=" << AM << "   AL=" << AL << endl ;
    
    int Bcut = 56;
    int Ccut = 35 ;




 


    //input variables to build report first line
    std::string group,name,surename,sex,homework,attendance;
    std::string T1,T2,T3,T4,T5,T6,T7,marks,grade,A,B,C,D,E,predicted,tes1,tes2,tes3,home1,home2,home3;
    
    unsigned int ClassMarkAve, ClassMarkDIS ;
    unsigned int ClassMarkMAX,ClassMarkMIN ;
    float ClassMarkSTD ;
    
    
    int sus;
    int Q1,Q2,Q3,Q4,Q5,Q6,Q7,mark;
    int homework1,homework2,homework3,test1,test2,test3;
    

    // Skiping very first line
    getline(InputFile, line);
    // reading first line to get the topics
    getline(InputFile, line);
    std::stringstream aa(line);
    aa >> group >> surename >> name >> sex >> T1 >> T2 >> T3 >> T4 >> T5 >> T6 >> T7 >> marks >> grade >> predicted >> tes1 >> tes2 >> tes3 >> home1 >> home2 >> home3 ;
    


    cout << "File headers" << endl ;
    cout << YELLOW << group << " " << surename << " " << name << " " << sex << " " << T1 << " " << T2 << " " << T3 << " " << T4 << " " << T5 << " " << T6 << " " << T7 << " " << marks << " " << grade << " " << predicted << " " << tes1 << " " << tes2 << " " << tes3 << " " << home1 << " " << home2 << " " << home3 << RESET << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    
    
    

    
    
while (getline(InputFile, line))
{
    std::stringstream aa(line) ;
    aa >> group >> surename >> name >> sex >> Q1 >> Q2 >> Q3 >> Q4 >> Q5 >> Q6 >> Q7 >> mark >> grade >> predicted >> test1 >> test2 >> test3 >> homework1 >> homework2 >> homework3 ;

            // Checks correct input
            // cout << YELLOW << group << " " << surename << " " << name << " " << sex << " " << Q1 << " " << Q2 << " " << Q3 << " " << Q4 << " " << Q5 << " " << Q6 << " " << Q7 << " " << marks << " " << grade << " " << predicted << " " << test1 << " " << test2 << " " << test3 << " " << homework1 << " " << homework2 << " " << homework3 << RESET << endl ;
    
           
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
            



        // Class test average
        ClassMarkAve= (test1 + test2 + test3)/3;
        // In case someone miss an exam...
        if ( test1 == 0 ){ClassMarkAve= (test2 + test3)/2;}
        if ( test2 == 0 ){ClassMarkAve= (test1 + test3)/2;}
        if ( test3 == 0 ){ClassMarkAve= (test1 + test2)/2;}



        // cout << YELLOW << group << "Class test average: " << ClassMarkAve << RESET << endl ;
        


        // Class test dispersion definition (standard deviation does not work for small samples)
        int ClassMarkMAX;
        int ClassMarkMIN;

        ClassMarkMAX = std::max({test1, test2,test3});
        ClassMarkMIN = std::min({test1, test2,test3});
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



 
        
        // std::cout << "max class test=" << ClassMarkMAX << "\n";
        // std::cout << "min clas test =" << ClassMarkMIN << "\n";

        ClassMarkDIS = ClassMarkMAX-ClassMarkMIN ;

        // cout << YELLOW << group << "Class test dispersion (dis): " << ClassMarkDIS << RESET << endl ;


            
            
 
            
            //-----------------
            // Topics to revise
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
            
           // cout << name <<" should revise " << CountTopics << " topics" <<endl;
//            cout << name <<" should revise " << ToRevise << " length" << ToRevise.length()<< endl ;
            
            
            
            
            // If CountTopics=1 topic singular
            // If CountTopics>1 topics plural
            if ( CountTopics == 1 ){toto = 0; }
            if ( CountTopics > 1 ){toto = 1; }

            if ( CountTopics <= 4 ){alltopics = 0; }
            if ( CountTopics > 4 ){alltopics = 1; }


            int HomeworkAve;
            int HomeworkLack = 0; // needs initiallise
            // Homework checker
            // quality:
            HomeworkAve = ( homework1 + homework2 + homework3 )/3;
            // Missing
            if ( homework1 == 0 ){HomeworkLack = 1;}
            if ( homework2 == 0 ){HomeworkLack = 1;}
            if ( homework3 == 0 ){HomeworkLack = 1;}

            


            //--------------------------------------------------------------
            // Heading line out to have a reference before report is written
            //--------------------------------------------------------------
            cout << endl ;
            cout << endl ;
            cout << endl ;
            cout << name << " " << surename << " " << group << endl ;
            cout << "(Mark= " << mark << "  Grade " << grade << " class min " << ClassMarkMIN << " class max " << ClassMarkMAX << " Class ave: " << ClassMarkAve << " Class dis: " << ClassMarkDIS << " Homework ave: " << HomeworkAve  << " Homework lack: " << HomeworkLack << " to revise: " << CountTopics << " topics)" << endl ;
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





//             //*****************************
//             // A grade starts here
//             //*****************************

//             // Exam comment
            if ( mark >= AH )
            {
                cout << name << " " << Achi[choicesa3] << " " << top[choicesb3] << " result in " << hisher[sus] << " Summer examination.  ";
            
            // Year performance based on class averages and dispersion and homework average
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }

            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a very high and consistent standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year  .  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << "Altough, " << hisher[sus] << " class average was consistently lower throughout the year  .  " << Cheshe[sus]  << " prepared really well for " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << "Altough, " << hisher[sus] << " class marks were irregular and lower throughout the year  .  " << Cheshe[sus]  << " prepared really well for " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not


            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve < 70 )
            {
                // cout << "There is still room for improvement.  ";
                // cout << "There is potential for improvement.  ";
                cout << "To do even better, ";
                // cout << "In order to improve, ";
                // cout << "To further improve, ";
                // cout << "To enhance learning, ";
                // cout << "To progress, ";


                if ( HomeworkAve < 70 && HomeworkLack == 1 )
                {
                    // Completing all homework is very important
                    // Quality completion of homework is fundamental to improve.
                //cout << Cheshe[sus] << " must complete all " << hisher[sus] << " homework and improve its quality.  ";
                cout << "Quality completion of all homework is fundamental.  ";
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
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << " A thorough review of all topics covered in this course is important to consolidate " << hisher[sus] << " knowledge.  " ;
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

            











            
            if ( mark < AH && mark >= AM )
            {
                cout << name << " " << Achi[choicesa3] << " " << Excellence[choicesa2] << " result in " << hisher[sus] << " Summer examination.  ";

            // Year performance based on class averages and dispersion and homework average
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }

            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a very high and consistent standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year  .  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << "Although, " << hisher[sus] << " class average was consistently lower throughout the year  .  " << Cheshe[sus]  << " prepared really well for " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve  && ClassMarkDIS > 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were irregular and lower throughout the year  .  " << Cheshe[sus]  << " prepared really well for " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve < 70 )
            {
                cout << "To do even better, ";

                if ( HomeworkAve < 70 && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve < 70 && HomeworkLack == 1 )
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
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << " A thorough review of all topics covered in this course is important to consolidate " << hisher[sus] << " knowledge.  " ;
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
        
            
        







            
            
            if ( mark < AM && mark >= AL )
            {
                cout << name << " " << Achi[choicesa3] << " " << Goodness[choicesa3] << " result in " << hisher[sus] << " Summer examination.  " ;

            // Year performance based on class averages and dispersion and homework average
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }

            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations " << AsRequired[choicesa5] << ".  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << "Although, " << hisher[sus] << " class average was consistently lower throughout the year.  " << Cheshe[sus]  << " prepared really well for " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve  && ClassMarkDIS > 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were irregular and lower throughout the year.  " << Cheshe[sus]  << " prepared really well for " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve < 70 )
            {
                cout << "To do even better, ";

                if ( HomeworkAve < 70 && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve < 70 && HomeworkLack == 1 )
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
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << " A thorough review of all topics covered in this course is important to consolidate " << hisher[sus] << " knowledge.  " ;
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
            

//            }
            // End of A grade

            



//             //class marks were irregular and lower throughout the year.
//             //Class assesment result were irregular and lower throughout the year. 
            

















            //*****************************
            // B grade starts here (no so bad)
            //*****************************


            if ( mark < AL && mark >= Bcut )
            {
                cout << name << " " << Achi[choicesa3] << " " << MediumHigh[choicesa3] << " result in " << hisher[sus] << " Summer examination.  " ;

            // Year performance based on class averages and dispersion and homework average
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year, unfortunately this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a consistent standard throughout the year which is compatible with " << hisher[sus] << " summer grade.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained an irregular standard throughout the year which is still compatible with " << hisher[sus] << " summer grade.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were consistently lower throughout the year, " << heshe[sus]  << " improved " << hisher[sus] << " standard for the Summer examination.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << "Although, " << hisher[sus] << " class marks were irregular and lower throughout the year, " << heshe[sus]  << " improved " << hisher[sus] << " standard for the Summer examination.  " ;
            }
            // Idem dispersion or not



            // Any of this conditions or one or other or etc activates room for improvement

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve < 70 )
            {
                cout << "To do even better, ";

                if ( HomeworkAve < 70 && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve < 70 && HomeworkLack == 1 )
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
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << " A thorough review of all topics covered in this course is important to consolidate " << hisher[sus] << " knowledge.  " ;
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
            // C grade starts here (the reality... bad)
            //*****************************


            if ( mark < Bcut && mark >= Ccut )
            {
                cout << name << " " << Achi[choicesa3] << " " << MediumLow[choicesb3] << " result in " << hisher[sus] << " Summer examination.  " ;

            // Year performance based on class averages and dispersion and homework average
            
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year, unfortunately this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not


            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a good but slightly irregular standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained a good and consistent standard throughout the year, unfortunately this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
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

            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve < 70 )
            {
                cout << "In order to progress, ";

                if ( HomeworkAve < 70 && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve < 70 && HomeworkLack == 1 )
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
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all topics covered in this course should be made.  " ;
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

            if ( mark < Ccut )
            {
                cout << name << " obtained " << Badness[choicesb3] << " result in " << hisher[sus] << " Summer examination.  " ;
                // instead of Achi[choicesa3] obtained
            // Year performance based on class averages and dispersion and homework average
            

            // Not likely
            if ( ClassMarkAve >= 90 )
            {
            cout << Cheshe[sus] << " has maintained an exceptionally high standard throughout the year, surprisingly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            
            if ( 90 > ClassMarkAve && ClassMarkAve >= 80 )
            {
            cout << Cheshe[sus] << " has maintained a consistent very high standard throughout the year, incomprehensibly this was not reflected in " << hisher[sus] << " Summer examination.  " ;
            }


            // Not likely
            // Idem dispersion or not
            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS <= 25)
            {
            cout << Cheshe[sus] << " has maintained a consistent high standard throughout the year, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 80 > ClassMarkAve && ClassMarkAve >= 70 && ClassMarkDIS > 25)
            {
            cout << Cheshe[sus] << " has maintained a high but slightly irregular standard throughout the year, surprisingly this was not fully reflected in " << hisher[sus] << " Summer examination.  " ;
            }
            // Idem dispersion or not



            // Not likely
            // Idem dispersion or not
            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS <= 25 )
            {
            cout << Cheshe[sus] << " has maintained a fair and consistent standard throughout the year,  unfortunately " << heshe[sus] << " underperformed in " << hisher[sus] << " Summer examination.  " ;
            }

            if ( 70 > ClassMarkAve && ClassMarkAve >= 60 && ClassMarkDIS > 25 )
            {
            cout << Cheshe[sus] << " has maintained an inconsistent standard throughout the year.  " ;
            }
            // Idem dispersion or not



            // Idem dispersion or not
            if ( 60 > ClassMarkAve && ClassMarkDIS <= 25 )
            {
            cout << Chisher[sus] << " performance was consistently poor throughout the course.  " << heshe[sus] << " is compromising " << hisher[sus] << " potential through lack of effort.  " ;
            }

            if ( 60 > ClassMarkAve && ClassMarkDIS > 25 )
            {
            cout << Chisher[sus] << " performance was inconsistent and poor throughout the course.  " ;
            }
            // Idem dispersion or not




            // Any of this conditions or one or other or etc activates room for improvement


                // if ( HomeworkAve > 70 && HomeworkLack == 0 )
                // {
                // cout << hisher[sus] << " homework was of high standard.  ";
                // }


            if ( CountTopics != 0 || HomeworkLack == 1 || HomeworkAve < 70 )
            {
                cout << "In order to progress, a much more committed approach is necessary.  ";

                if ( HomeworkAve < 70 && HomeworkLack == 0 )
                {
                cout << "improve the quality of " << hisher[sus] <<" homework is fundamental.  ";
                }

                if ( HomeworkAve < 70 && HomeworkLack == 1 )
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
                    cout << Cheshe[sus] <<  " should revise the " << topikini[toto] << " " << ToRevise << " to consolidate " << hisher[sus] << " knowledge.  " ; 
                    }
                    else
                    {
                    cout << "A comprehensive review of all topics covered in this course should be made.  " ;
                    }   
                }
            cout << endl ; 
            cout << endl ; 
            }

            }






























            
            
        //     if ( mark < 70 && mark >= 60 )
        //     {
        //         cout << "This is " << MediumLow[choicesa2] << " mark and very well deserved.  " << name << " has maintained an exceptionally high standard throughout the year.  " << Cheshe[sus]  << " grasps new physical concepts with ease and can select and apply equations in a variety of ways.  "  ;
                
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