#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

class MillionaireGame {
private:
    struct Question {
        string questionText;
        vector<string> options;
        char correctOption;
    };

    vector<Question> allQuestions; 
    vector<Question> selectedQuestions; 
    int currentQuestion;
    int moneyWon;

    bool FiftyFiftyUsed = false;
    bool SwapQuestionUsed = false;
    bool AudienceHelpUsed = false;

public:
    MillionaireGame() : currentQuestion(0), moneyWon(0) {
        initializeAllQuestions();
        selectRandomQuestions();
    }


    void initializeAllQuestions() {
        Question q1 = { "Gdzie �l�zaczki nosz� laczki?", {"A. Na g�owie", "B. Na r�kach", "C. Na nogach", "D. Na plecach"}, 'C' };
        allQuestions.push_back(q1);
        Question q2 = { "Ragdoll, czyli szmaciana lalka, to rasa...", {"A. Kot�w", "B. Ps�w", "C. Kr�lik�w", "D. Chomik�w"}, 'A' };
        allQuestions.push_back(q2);
        Question q3 = { "Ile kosztuje chleb, kt�ry pierwotnie kosztowa� 10 z�, nast�pnie potania� do 8 z�, a p�niej jego cena wzros�a o 20 proc.?", {"A. 8,20 z�", "B. 9 z�", "C. 9,60 z�", "D. 10 z�"}, 'C' };
        allQuestions.push_back(q3);
        Question q4 = { "Co jest prawd� o podkarpackim mie�cie, kt�re ma w nazwie urz�dzenie w��kiennicze?", {"A. s�ynie z hut szk�a", "B. w X w. by�o stolic� Polski", "C. ma milion mieszka�c�w", "D. ma w herbie ��d�"}, 'A' };
        allQuestions.push_back(q4);
        Question q5 = { "Kuchenny synonim przekr�tu...", {"A. t�uczek", "B. wa�ek", "C. blat", "D. garnek"}, 'B' };
        allQuestions.push_back(q5);
        Question q6 = { "Kojot wygl�da jak co� pomi�dzy...", {"A. rysiem a �bikiem", "B. bobrem a wiewi�rk�", "C. kun� a �asic�", "D. wilkiem a szakalem"}, 'D' };
        allQuestions.push_back(q6);
        Question q7 = { "Kto w marcu 2023 r. w meczu z Albani� w trakcie eliminacji do Euro strzeli� zwyci�skiego gola dla Polski?", {"A. Jan Bednarek", "B. Piotr Zieli�ski", "C. Karol �widerski", "D. Robert Lewandowski"}, 'C' };
        allQuestions.push_back(q7);
        Question q8 = { "Jaka jest �rednia wieku w grupie sk�adaj�cej si� z trzech 4-latk�w, czterech 11-latk�w, dw�ch 12-latk�w i jednego 20-latka?", {"A. 10 lat", "B. 8 lat", "C. 15 lat", "D. 18 lat"}, 'A' };
        allQuestions.push_back(q8);
        Question q9 = { "Awanturka to pasta...", {"A. polerska", "B. cukrowa", "C. do kanapek", "D. do but�w"}, 'C' };
        allQuestions.push_back(q9);
        Question q10 = { "Trzy zwyczaje ��cz� si� z noc� �wi�toja�sk�, a jeden nie. Kt�ry?", {"A. szukanie kwiatu paproci", "B. puszczanie wiank�w nad wod�", "C. skoki przez ognisko", "D. topienie marzanny"}, 'D' };
        allQuestions.push_back(q10);
        Question q11 = { "Kt�ry z ptak�w kuka?", {"A. samica kuku�ki", "B. samiec kuku�ki", "C. samica g�eg��ki", "D. samica zazuli"}, 'B' };
        allQuestions.push_back(q11);
        Question q12 = { "Co pojawia si� w znanym �ama�cu j�zykowym o czytaj�cym tacie?", {"A. passusy Passenta", "B. wersy z Verne'a", "C. maksymy Maksymusa", "D. cytaty z Tacyta"}, 'D' };
        allQuestions.push_back(q12);
        Question q13 = { "To klasyczny kszta�t kobiecych brwi...", {"A. mysie ogonki", "B. kocie grzbiety", "C. skrzyd�a jask�ki", "D. strza�y Amora"}, 'C' };
        allQuestions.push_back(q13);
        Question q14 = { "Kt�ry to legendarny angielski pirat?", {"A. Sinobrody", "B. Czarnobrody", "C. D�ugonogi", "D. Krzywousty"}, 'B' };
        allQuestions.push_back(q14);
        Question q15 = { "O co chodzi we frazeologizmie: co� jest warte lub niewarte zachodu?", {"A. o kierunek geograficzny", "B. o mekk� dla Polak�w za PRL-u", "C. o czasownik zabieganie", "D.o czasownik wybieganie"}, 'C' };
        allQuestions.push_back(q15);
        Question q16 = { "Kt�rego kraju stolica ma najwi�cej liter?", {"A. Madagaskaru", "B. Kenii", "C. Egiptu", "D. Maroko"}, 'A' };
        allQuestions.push_back(q16);
        Question q17 = { "W wilka i w owce najcz�ciej gra si� na planszy...", {"A. do chi�czyka", "B. do warcab�w", "C. do scrabble", "D. do m�ynka"}, 'B' };
        allQuestions.push_back(q17);
        Question q18 = { "Ile odcink�w prostych znajdziemy w rzymskiej cyfrze 50?", {"A. siedem", "B. pi��", "C. dwa", "D. jeden"}, 'C' };
        allQuestions.push_back(q18);
        Question q19 = { "Jakie lekarstwo na problemy z pami�ci� zaordynowa� S�oniowi Tr�balskiemu kowal z wiersza Juliana Tuwima?", {"A. podkucie przednich n�g", "B. przek�ucie uszu", "C. supe�ek na tr�bie", "D. kokardk� na ogonie"}, 'C' };
        allQuestions.push_back(q19);
        Question q20 = { "Kto zdoby� Z�ot� Pi�k� w 2018 roku?", {"A. Lionel Messi", "B. Cristiano Ronaldo", "C. Robert Lewandowski", "D. Luka Modri�"}, 'D' };
        allQuestions.push_back(q20);


        random_shuffle(allQuestions.begin(), allQuestions.end());
    }

    void selectRandomQuestions() {
        selectedQuestions.clear();
        for (int i = 0; i < 10 && i < allQuestions.size(); ++i) {
            selectedQuestions.push_back(allQuestions[i]);
        }
    }

    void displayQuestion() {
        cout << "Pytanie " << currentQuestion + 1 << ": " << selectedQuestions[currentQuestion].questionText << endl;
        for (int i = 0; i < 4; ++i) {
            cout << selectedQuestions[currentQuestion].options[i] << endl;
        }
    }

    void FiftyFifty() {
        vector<char> availableOptions = { 'A', 'B', 'C', 'D' };
        availableOptions.erase(remove(availableOptions.begin(), availableOptions.end(), selectedQuestions[currentQuestion].correctOption), availableOptions.end());
        random_shuffle(availableOptions.begin(), availableOptions.end());
        for (int i = 0; i < 2; ++i) {
            char removedOption = availableOptions.back();
            availableOptions.pop_back();
            for (auto& option : selectedQuestions[currentQuestion].options) {
                if (option[0] == removedOption) {
                    option = " ";
                }
            }
        }
    }

    void SwapQuestion() {
        cout << "Zamiana pytania! Oto nowe pytanie:" << endl;
        int newIndex = rand() % allQuestions.size();
        selectedQuestions[currentQuestion] = allQuestions[newIndex];
    }

    void AudienceHelp() {
        cout << "Publiczno�� my�li..." << endl;
        int correctPercentage = rand() % 51 + 50;
        int incorrectPercentage = 100 - correctPercentage;

        cout << "A: " << (selectedQuestions[currentQuestion].correctOption == 'A' ? correctPercentage : incorrectPercentage) << "%   "
            << "B: " << (selectedQuestions[currentQuestion].correctOption == 'B' ? correctPercentage : incorrectPercentage) << "%   "
            << "C: " << (selectedQuestions[currentQuestion].correctOption == 'C' ? correctPercentage : incorrectPercentage) << "%   "
            << "D: " << (selectedQuestions[currentQuestion].correctOption == 'D' ? correctPercentage : incorrectPercentage) << "%" << endl;
    }

    bool answerQuestion(char userAnswer) {
        if (userAnswer == 'L') {
            if (!FiftyFiftyUsed) {
                FiftyFifty();
                cout << "U�y�e� ko�a ratunkowego \"P� na p�\"!" << endl;
                FiftyFiftyUsed = true; 
            }
            else {
                cout << "To ko�o ratunkowe zosta�o ju� u�yte!" << endl;
            }
        }
        else if (userAnswer == 'Z') {
            if (!SwapQuestionUsed) {
                SwapQuestion();
                cout << "U�y�e� ko�a ratunkowego \"Zamiana pytania\"!" << endl;
                SwapQuestionUsed = true;
            }
            else {
                cout << "To ko�o ratunkowe zosta�o ju� u�yte!" << endl;
            }
        }
        else if (userAnswer == 'P') {
            if (!AudienceHelpUsed) {
                AudienceHelp();
                cout << "U�y�e� ko�a ratunkowego \"Pytanie do publiczno�ci\"!" << endl;
                AudienceHelpUsed = true; 
            }
            else {
                cout << "To ko�o ratunkowe zosta�o ju� u�yte!" << endl;
            }
           }
        else {
            if (userAnswer == selectedQuestions[currentQuestion].correctOption) {
                cout << "Poprawna odpowied�! Wygrywasz " << calculatePrize() << " z�!" << endl;
                ++currentQuestion;
                if (currentQuestion == selectedQuestions.size()) {
                    cout << "Gratulacje! Wygra�e� ca�� gr�!" << endl;
                    return false; 
                }
                return true;
            }
            else {
                cout << "Niestety, z�a odpowied�. Koniec gry." << endl;
                return false;
            }
        }

        return true;
    }

    int calculatePrize() {
        return 1000 * (currentQuestion + 1);
    }
};

int main() {

    setlocale(LC_ALL, "");
    srand(time(0)); 
    MillionaireGame game;
    char userAnswer;

    cout << "Witaj w grze \"Mini Milionerzy\"! Odpowiedz na pytania, aby wygra� 10 000 z�otych!" << endl;
    
    do {
        game.displayQuestion();
        cout << "Podaj odpowied� (A, B, C, D) lub skorzystaj z k� ratunkowych (L - P� na p�, Z - Zamiana pytania, P - Pytanie do publiczno�ci): ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);
    } while (game.answerQuestion(userAnswer));
   
    
    return 0;
}













