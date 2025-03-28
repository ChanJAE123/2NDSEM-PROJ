#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

/*

CODE PARTS:
• Structure
• QUIT FUNCTION
• Display (Sorted) FUNCTION
• Insertion (Add Data)
• Deletion (Remove Data)
• Load ()
• Save 
• Search FUNCTION
• About FUNCTION

TO DO: 
• file handling (load)
• possible solution sa dilemma;

NOTE: may instances na mag error sa ibang IDE/online compiler since may pre-defined functions na di compatible sa iba like "system("cls");"

*/

struct Dilemma
{
    string dilemma, category, solution;
}; // 

// para sa file handling (fstream)
fstream File;

// declaration ng dynamic structure na array w/ size na
Dilemma *dilemmas = nullptr;
int size = 0;

string toUpper(string text)
{
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}


int quiting() // !!OKAY NA!!
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
        << string(54, ' ')  << "\n";
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
                    << "   SOLUTION: " << dilemmas[j].solution << "\n";
                    checker = true;
                    counter++;
                }
            }

            if (!checker)
            {
                cout << "   - None." << "\n";
            }
            cout << "\n";
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
        cin.ignore();
        getline(cin, temp[size].solution);

        firstLetterofSolution = temp[size].solution[0];

        if (!isalpha(firstLetterofSolution))
        {
            cout << "  Must Enter a possible solution!\n";
            continue;
        }
    } while (!isalpha(firstLetterofSolution));
// ---
    string added = temp[size].dilemma;

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

void load()
{
    ;    // idk
}

void save() // OKAY NA (ata? HAHAHAHA)
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
        << "             EMPTY! NO DILEMMAS TO SAVE!             " << "\n"
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n";
    }
    else
    {
        string filename;

        cout 
        << string(54, ' ') << "\n"
        << string(54, ' ') << "\n"
        << "  Enter Filename: ";
        cin.ignore();
        getline(cin, filename);
        cout
        << string(54, ' ') << "\n"
        << string(54, ' ');
                                         // depends sa kung kung saang directory nyo gusto isave, hindi pare parehas (logic)
        string directory_ng_file = "C:\\Users\\MyPC\\Desktop\\I.T\\SCHOOL PURPOSES\\.vscode\\.vscode\\console-based proj\\DATAS (!ADMIN ONLY!)\\" + filename + ".txt";

        File.open(directory_ng_file, ios::out);

        File << "DILEMA RECORDS" << size << "\n";

        File
        << "\nDATA SHEET FORMAT: " << "\n"
        << "• DATA/S" << "\n"
        << "• ATTRIBUTES" << "\n"
        << "  - Category (header)\n  - Dilemma\n  - Solution" << "\n\n";

        string category[3] = {"Least Severe", "Severe", "Most Severe"};

        for (int j = 0; j < 3; j++)
        {   
            bool checker = false;
            string CATEGORY = category[j];
            CATEGORY = toUpper(CATEGORY);
            File << toUpper(category[j]) << ": \n";
            for (int i = 0; i < size; i++)
            {
                if (dilemmas[i].category == category[j])
                {
                    File << 'D' << i+1 << ": " << dilemmas[i].dilemma << "\n";
                    File << 'D' << i+1 << ": " << dilemmas[i].solution << "\n";
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

void search() // DI PA
{
    system("cls");
    cout
    << ' ' << string(54, '=') << "\n"
    << "Search" << "\n";

    int search_op;
    do
    {
        cout
        << ' ' << string(54, '-') << "\n"
        << "|| 1. Back to Main Menu     2. Quit" << "\n"
        << ' ' << string(54, '-') << "\n"
        << "|| Enter your choice: ";
        cin >> search_op;

        if (search_op == 1)
        {
            return;
        }
        else if (search_op == 2)
        {
            quiting();
            exit(0);
        }

    } while (search_op != 1 || search_op != 2);
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
    Dilemma *dilemmas = new Dilemma[0];
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