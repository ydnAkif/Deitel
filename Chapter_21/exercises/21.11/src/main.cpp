#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char const *argv[])
{
    std::string response;
    int w = 0;
    const int WORDS = 4;

    do
    {
        const char body[] = " o/|\\|/\\";

        std::string words[WORDS] = {"MACAW", "SADDLE", "TOASTER", "XENOCIDE"};
        std::string xword(words[w].length(), '?');
        std::string::iterator i;
        std::string::iterator ix = xword.begin();
        char letters[26] = {'\0'};
        int n = 0;
        int xcount = xword.length();
        bool found = false;
        bool solved = false;
        int offset = 0;
        int bodyCount = 0;
        bool hung = false;

        std::cout << "Guess the word: ";

        for (unsigned loop = 0; loop < words[w].length(); ++loop)
            std::cout << "X";

        do
        {
            std::cout << "\n\nGuess a letter (case does not matter): "
                      << xword << "\n?";
            char temp;
            std::cin >> temp;

            if (!isalpha(temp))
            {
                std::cout << "\nLETTERS ONLY PLEASE!\n";
                continue;
            }

            letters[n] = toupper(temp);
            i = words[w].begin();
            found = false;
            offset = 0;

            while (i != words[w].end())
            {
                if (*i == letters[n])
                {
                    *(ix + offset) = *i;
                    found = true;

                    if (--xcount == 0)
                        solved = true;
                }

                ++i;
                ++offset;
            }

            if (!found)
                ++bodyCount;

            bool newLine = false;

            for (int q = 1; q <= bodyCount; ++q)
            {
                if (q == 1 || q == 5 || q == 7)
                {
                    newLine = true;
                    std::cout << body[0];
                }
                else if (q == 4)
                    newLine = true;
                else
                    newLine = false;
                std::cout << body[q];

                if (newLine)
                    std::cout << '\n';
            }

            if (bodyCount == 7)
            {
                std::cout << "\n\n...GAME OVER...\n";
                hung = true;
                break;
            }

            std::cout << "\nYour guesses:\n";

            for (int k = 0; k <= n; ++k)
                std::cout << std::setw(2) << letters[k];
            ++n;

        } while (!solved);

        std::cout << "\n\nWord: " << words[w] << "\n\n";

        if (!hung)
            std::cout << "\nCongratulations!!! You guessed "
                      << "my word.\n";
        if (w++ >= WORDS)
            break;
        std::cout << "Play again (yes/no)? ";
        std::cin >> response;

    } while (!response.compare("yes"));

    std::cout << "\nThank you for playing hangman." << std::endl;

    return 0;
}
