#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

/*

NOTES: 
may instances na mag error sa ibang IDE or online compiler since may 
pre-defined functions na di compatible sa iba like "system("cls");"

MODIFY CATEGORY and DISPLAY (ADD MORE FUNCTION)
like: bubble sorting for category of dilemma

* - means required

array pointer gaamit ko, alternative: vector

CODE PARTS:
• Structure
• toUpper FUNCTION (optional)
• QUIT FUNCTION (di req na naka function pa pero need talaga to terminate the program)
• Display (Sorted) FUNCTION *
• Insertion (Add Data) FUNCTION *
• Deletion (Remove Data) FUNCTION *
• Load FUNCTION *
• Save FUNCTION *
• Search FUNCTION *
• About FUNCTION (gusto ko lang)

TO DO: MAKE IT MORE COMPLEX!!
• 
*/

struct Dilemma
{
    string dilemma, category, solution;
};

// para sa file handling (fstream)
fstream File;

// declaration ng dynamic structure na array w/ size na
Dilemma *dilemmas = new Dilemma[0];
int size = 0;

string toUpper(string text) // Just to convert letters sa string to Uppercase (not required)
{
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}

void quiting() // !!OKAY NA!!
{
    system("cls");
    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(52, ' ') << "||" << "\n" 
    << "||" << string(52, ' ') << "||" << "\n" 
    << "||        YOU'VE SUCCESSFULLY LEFT THE PROGRAM        ||" << "\n"
    << "||" << string(52, ' ') << "||" << "\n" 
    << "||" << string(52, ' ') << "||" << "\n" 
    << ' ' << string(54, '=') << "\n";
}

void display() // !! OKAY NA !!
{
    
// modify make it look more complex
// ask first the user if he/she want to display the datas by sorted or by time input;


    system("cls");
    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(15, ' ') <<  "ETHICAL DILEMMA DATA/S" << string(15, ' ') << "||" << "\n"
    << ' ' << string(54, '-') << "\n\n";

    if (size == 0)
    {
        cout 
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n"
        << "             EMPTY! No Dilemmas to Display!           " << "\n"
        << string(54, ' ')  << "\n"
        << string(54, ' ')  << "\n\n";
    }
    else
    {
        string categories[3] = {"Least Severe", "Severe", "Most Severe"};

        for (int i = 0; i < 3; i++)
        {
            bool checker = false;
            int counter = 1;

            cout
            << "  " << categories[i] << ':' << "\n";

            for (int j = 0; j < size; j++)
            {   
                if (dilemmas[j].category == categories[i])
                {
                    cout
                    << "   " << counter << ". " << dilemmas[j].dilemma << "\n"
                    << "   SOLUTION: " << dilemmas[j].solution << "\n\n";
                    checker = true;
                    counter++;
                }
            }

            if (!checker)
            {
                cout << "   - None." << "\n";
            }
            cout << "\n\n";
        }
    }

    int display_op;
    do
    {
        cout
        << ' ' << string(54, '-') << "\n"
        << "||                1. Back to Main Menu                ||" << "\n"
        << ' ' << string(54, '=') << "\n"
        << "    >>: ";
        cin >> display_op;

        if (display_op == 1)
        {
            return;
        }
    } while (display_op != 1);
}

void insertion() // GOODS NA
{
    int ins_choice;

    system("cls");
    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(21, ' ') <<  "INSERT DATA" << string(20, ' ') << "||" << "\n"
    << ' ' << string(54, '-') << "\n";

    Dilemma *temp = new Dilemma[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = dilemmas[i];
    }

    do
    {
        cout
        << "  CATEGORIES: " << "\n"
        << "  1. Least Severe." << "\n"
        << "  2. Severe." << "\n"
        << "  3. Most Severe." << "\n"
        << ' ' << string(54, '-') << "\n"
        << "  CATEGORY: ";
        cin >> ins_choice;

        switch (ins_choice)
        {
            case 1:
                temp[size].category = "Least Severe";   break;
            case 2:
                temp[size].category = "Severe";         break;
            case 3:
                temp[size].category = "Most Severe";    break;
            default:
                cout << "  Invalid!" << "\n";
                continue;
        }
        break;
    } while (true);
    
    cout 
    << "  DILEMMA: ";
    cin.ignore();
    getline(cin, temp[size].dilemma);

    char firstLetterofSolution;
    // --
    do
    {
        cout
        << "  SOLUTION: ";
        getline(cin, temp[size].solution);

        firstLetterofSolution = temp[size].solution[0];

        if (!isalpha(firstLetterofSolution))
        {
            cout << "  Must Enter a possible solution!\n";
            continue;
        }
    } while (!isalpha(firstLetterofSolution));

    delete[] dilemmas;
    dilemmas = temp;
    size++;

    cout 
    << ' ' << string(54, '-') << "\n"
    << "                   NEW DILEMMA ADDED!                 \n"
    << "                 WITH POSSIBLE SOLUTION!                 \n";
    

    int ins_op;
    do
    {
        cout
        << ' ' << string(54, '-') << "\n"
        << "||  1. Add New                  2. Back to Main Menu  ||" << "\n"
        << ' ' << string(54, '=') << "\n"
        << "  >>: ";
        cin >> ins_op;

        if (ins_op == 1)
        {
            insertion();
        }
        else if (ins_op == 2)
        {
            return;
        }

    } while (ins_op != 1 && ins_op != 2);

}

void deletion() // TAPOS NA !!
{

    system("cls");
    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(21, ' ') <<  "DELETE DATA" << string(20, ' ') << "||" << "\n"
    << ' ' << string(54, '-') << "\n";

    if (size == 0)
    {
        cout 
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n"
        << "             EMPTY! NO DILEMMAS TO DELETE!           " << "\n"
        << string(54, ' ')  << "\n"
        << string(54, ' ')  << "\n";

        int del_choice;
        do
        {
            cout
            << ' ' << string(54, '-') << "\n"
            << "||                1. Back to Main Menu                ||" << "\n"
            << ' ' << string(54, '=') << "\n"
            << "   >>: ";
            cin >> del_choice;
        } while (del_choice != 1);
        return;
    }
    else
    {
        string categories[3]  = {"Least Severe", "Severe", "Most Severe"};
        int* pos = new int[size];

        for (int i = 0; i < 3; i++)
        {
            bool checker = false;

            cout 
            << "  " << categories[i] << ':' << "\n";

            for (int j = 0; j < size; j++)
            {
                if (dilemmas[j].category == categories[i])
                {
                    cout << "    " << j + 1 << ". " << dilemmas[j].dilemma << "\n";
                    pos[j] = j;
                    checker = true;
                }
            }
            if (!checker)
            {
                cout << "    - None." << "\n";
            }
            cout << "\n";
        }

        int del_pos;
        
        do
        {
            cout 
            << string(54, '-') << "\n"
            << " Position to Delete: ";
            cin >> del_pos;

            if (del_pos < 1 || del_pos > size)
            {
                cout << "Invalid!" << "\n";
                continue;
            }
            break;
        } while (true);

        string deleted = dilemmas[del_pos - 1].dilemma; // saving deleted dilemaahh!!!
        Dilemma *temp = new Dilemma[size - 1];

        for (int i = 0; i < del_pos - 1; i++)
        {
            temp[i] = dilemmas[i];   // copy (before delete pos)
        }

        for (int i = del_pos; i < size; i++)
        {
            temp[i - 1] = dilemmas[i]; // copy (after delete pos)
        }

        delete[] dilemmas;
        dilemmas = temp;
        size--;
        
        if (deleted.size() <= 30)
        {
        cout
        << string(54, '-') << "\n"
        << " DILEMMA DELETED: "<< deleted <<"\n";
        }
        else
        {
            cout
            << string(54, '-') << "\n"
            << "                  DILEMMA DELETED!                 \n";
        }

        int del_choice;
        do
        {
            cout
            << string(54, '-') << "\n"
            << "  1. Delete Another             2. Back to Main Menu" << "\n"
            << string(54, '=') << "\n"
            << "  >>: ";
            cin >> del_choice;

            if (del_choice == 1)
            {
                deletion();
            }
            else if (del_choice == 2)
            {
                return;
            }
        } while (del_choice != 1 && del_choice != 2);
    }
}

void load() // DONE
{
    system("cls");

    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(21, ' ') <<  "LOAD DATA" << string(22, ' ') << "||" << "\n"
    << ' ' << string(54, '-') << "\n";

    string filename;
    
    cout
    << "  File Name: ";
    cin.ignore();
    getline(cin, filename);

    cout << ' ' << string(54, '-') << "\n";

    string directory_ng_file = "C:\\Users\\MyPC\\Desktop\\I.T\\SCHOOL PURPOSES\\.vscode\\.vscode\\console-based proj\\DATAS (!ADMIN ONLY!)\\" + filename + ".txt";

    File.open(directory_ng_file, ios::in);

    if (!File.is_open())
    {
        cout
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n"
        << "                  FILE DOESN'T EXIST!             " << "\n"
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n";
    }
    else
    {
        string line;
        for (int i = 0; i < 10; i++)
        {
            getline(File, line);
        }

        Dilemma *temp = new Dilemma[100];
        int loaded = 0;

        string current_category;
        while(getline(File, line))
        {
            if (line.find("SEVERE") != string::npos)
            {
                if (line.find("MOST") != string::npos)
                {
                    current_category = "Most Severe";
                }
                else if (line.find("LEAST") != string::npos)
                {
                    current_category = "Least Severe";
                }
                else
                {
                    current_category = "Severe";
                }
            }
            else if (line[0] == 'D')
            {
                temp[loaded].category = current_category;
                temp[loaded].dilemma = line.substr(line.find(": ") + 2);
                
                //getline(File, line);
                temp[loaded].solution = line.substr(line.find(": ") + 2);

                
                loaded++;

                getline(File, line);
                getline(File, line);
            }
        }

        if (loaded > 0)
        {
            delete[] dilemmas;
            dilemmas = new Dilemma[loaded];
            
            for (int i = 0; i < loaded; i++)
            {
                dilemmas[i] = temp[i];
            }

            size = loaded;
        }

        delete[] temp;

        File.close();

        cout
        << "                      DATA LOADED!                   " << "\n";
    }

    int load_op;
    do
    {
        cout
        << ' ' << string(54, '-') << "\n"
        << "||                1. Back to Main Menu                ||" << "\n"
        << ' ' << string(54, '=') << "\n"
        << "    >>: ";
        cin >> load_op;
    } while (load_op != 1);

    return;
}

void save() // DONE
{
    system("cls");

    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(21, ' ') <<  "SAVE DATA" << string(22, ' ') << "||" << "\n"
    << ' ' << string(54, '-') << "\n";

    if (size == 0)
    {
        cout
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n"
        << "               EMPTY! NO DILEMMAS TO SAVE!             " << "\n"
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n";
    }
    else
    {
        string filename;

        cout 
        << "  File Name: ";
        cin.ignore();
        getline(cin, filename);

                                         // depends sa kung kung saang directory nyo gusto isave, hindi pare parehas (logic)
        string directory_ng_file = "C:\\Users\\MyPC\\Desktop\\I.T\\SCHOOL PURPOSES\\.vscode\\.vscode\\console-based proj\\DATAS (!ADMIN ONLY!)\\" + filename + ".txt";

        File.open(directory_ng_file, ios::out);

        File << "DILEMA RECORDS" << size << "\n";

        File
        << "\nDATA SHEET FORMAT: " << "\n"
        << "• DATA/S" << "\n"
        << "• ATTRIBUTES" << "\n"
        << "  - Category (header)\n  - Dilemma\n  - Solution" << "\n\n\n";

        string category[3] = {"Least Severe", "Severe", "Most Severe"};

        for (int j = 0; j < 3; j++)
        {   
            bool checker = false;
            string CATEGORY = category[j];
            CATEGORY = toUpper(CATEGORY);
            File << CATEGORY << ": \n";
            for (int i = 0; i < size; i++)
            {
                if (dilemmas[i].category == category[j])
                {
                    File << 'D' << i+1 << ": " << dilemmas[i].dilemma << "\n";
                    File << 'S' << i+1 << ": " << dilemmas[i].solution << "\n";
                    File << "\n\n";
                    checker = true;
                }
            }
            if (!checker)
            {
                File << "  - None." << "\n\n";
            }
        }
        cout << "\n";

        File.close();

        cout
        << ' ' << string(54, '-') << "\n"
        << string(22, ' ') <<  "DATA SAVED!" << string(22, ' ')  << "\n";
    }

    int save_choice;
    do
    {
        cout
        << ' ' << string(54, '-') << "\n"
        << "||                1. Back to Main Menu                ||" << "\n"
        << ' ' << string(54, '=') << "\n"
        << "  >>: ";
        cin >> save_choice;

        if (save_choice == 1)
        {
            return;
        }
    } while (save_choice != 1);
}

void search() // DONE
{
    system("cls");
    cout
    << ' ' << string(54, '=') << "\n"
    << "||" << string(21, ' ') <<  "SEARCH DATA" << string(21, ' ') << "||" << "\n"
    << ' ' << string(54, '-') << "\n";

    if (size == 0)
    {
        cout 
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n"
        << "             EMPTY! No Dilemmas to Search!           " << "\n"
        << string(54, ' ')  << "\n"
        << string(54, ' ')  << "\n";
    }
    else
    {
        string search;
        cout
        << "  SEARCH: ";
        cin.ignore();
        getline(cin, search);

        cout << ' ' << string(54, '-') << "\n";

        cout
        << " RELATED DILEMMA/S: \n\n";
        bool found = false;
        int counter = 1;

        search = toUpper(search);

        for (int i = 0; i < size; i++)
        {
            string upperdilemma = toUpper(dilemmas[i].dilemma);

            if (upperdilemma.find(search) != string::npos)
            {
                cout
                << "  " << counter << ". " << dilemmas[i].dilemma << "\n"
                << "  CATEGORY: " << dilemmas[i].category << "\n"
                << "  SOLUTION: " << dilemmas[i].solution << "\n\n";
                found = true;
            }
        }

        if (!found)
        {
            cout 
            << string(54, ' ') << "\n"
            << string(54, ' ') << "\n"
            << "             NO MATCHING DILEMMAS FOUND!           " << "\n"
            << string(54, ' ')  << "\n"
            << string(54, ' ')  << "\n";
        }
    }


    int search_op;
    do
    {
        cout
        << ' ' << string(54, '-') << "\n"
        << "|| 1. Search Another              2. Back to Main Menu" << "\n"
        << ' ' << string(54, '-') << "\n"
        << " >>: ";
        cin >> search_op;

        if (search_op == 1)
        {
            search();
        }
        else if (search_op == 2)
        {
            return;
        }

    } while (search_op != 1 && search_op != 2);
}

void about() // STILL MISSING INFO (DESCRIPTION/ATBP.)
{
    int about_op;

    system("cls");

    do
    {
        cout
        << ' ' << string(54, '=') << "\n"
        << "||" << string(23, ' ') <<  "ABOUT" << string(24, ' ') << "||" << "\n"
        << ' ' << string(54, '-') << "\n"
        << "   Project Name: Ethical Dilemma Sorting System" << "\n"
        << "   Developed by: John Andrei E. Chan" << "\n\n"

        << "   Subject/s:"<< "\n"
        << "    - Data Structure and Algorithm" << "\n"
        << "    - Computer Programming 1" << "\n"
        << "    - Science, Technology, & Society" << "\n\n"

        << "   Professor/s:" << "\n"
        << "    - Mr. Arjonel Mendoza" << "\n"
        << "    - Mrs. Ligaya Lutero" << "\n"
        << "    - Ms. Hannah Carmela Marquez" << "\n\n"

        << "   Tools:" << "\n"
        << "   - Visual Studio Code (IDE)" << "\n"
        << "   - C++ (Programming Language)" << "\n"
        << "   - Claude 3.5 Sonnet (LLM)" << "\n\n"

        << "   Description:" << "\n"
        << "     This Console-Based Project was developed with AI" << "\n"
        << "     assistance, using Claude 3.5 Sonnet." << "\n"
        << "     Kung ano pang madadagdag." << "\n\n"

        << "   DATE CREATED: March 2025" << "\n";

        // pilian
        cout
        << ' ' << string(54, '-') << "\n"
        << "||                1. Back to Main Menu                ||" << "\n"
        << ' ' << string(54, '=') << "\n"
        << "   >>: ";
        cin >> about_op;

        if (about_op != 1)
        {
            continue;
        }
        else
        {
            return;
        }

    } while (about_op != 1);

}

int main()
{
    int choice;

    do
    {
        system("cls");
        cout
        << ' ' << string(54, '=') << "\n"
        << "||       ETHICAL DILEMMA DATA MANAGEMENT SYSTEM       ||" << "\n"
        << ' ' << string(54, '-') << "\n";

        cout 
        << "   1. Display (Sorted) Current Dilemmas." << "\n"
        << "   2. Search Dilemma." << "\n"
        << "   3. Insert New Dilemma." << "\n"
        << "   4. Delete Dilemma." << "\n"
        << "   5. Load." << "\n"
        << "   6. Save." << "\n"
        << "   7. About." << "\n"
        << "   8. Quit." << "\n"
        << ' ' << string(54, '=') << "\n"
        << "   >>: ";
        cin >> choice;

        switch (choice)
        {
            case 1: display(); break;
            case 2: search(); break;
            case 3: insertion(); break;
            case 4: deletion(); break;
            case 5: load(); break;
            case 6: save(); break;
            case 7: about(); break;
            case 8: quiting(); exit(0); break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 8);

    

    return 0;
}