#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char sentence[] = "This is a sentence with 7 tokens";

    std::cout << "The string to be tokenized is:\n"
              << sentence
              << "\n\nThe tokens are:\n\n";

    char *tokenPtr = strtok(sentence, " ");

    while (tokenPtr != NULL)
    {
        std::cout << tokenPtr << '\n';
        tokenPtr = strtok(NULL, " ");
    }

    std::cout << "\nAfter strtok, sentence = " << sentence << std::endl;

    return 0;
}
