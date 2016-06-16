/*
File: Reverse_Words.cpp
Author: Platwnas-Nikolaos Kiorpelidis
Purpose: Solution to Problem B - Reverse Words (Africa 2010, Qualification Round - Google Code Jam)
Date: 15-6-2016
Language: C++
*/

#include <iostream>
#include <cstdint>
using namespace std;

class Stack
{
  private:
    char **arr;
    uint32_t num_items;
    uint32_t stack_size;
    uint16_t max_word_length;
  public:
    Stack(uint32_t stack_size, uint16_t max_word_length)
    {
      //setting object's private variables.
      num_items = 0;
      this->stack_size = stack_size;
      this->max_word_length = max_word_length;

      //allocating space for the stack size & word size.
      arr = new char*[stack_size];
      if(arr == NULL)
      {
        cerr << "Error: Could not reserve memory for the stack size" << endl;
        exit(EXIT_FAILURE);
      }
      for(size_t item = 0; item < stack_size; item++)
      {
        arr[item] = new char[max_word_length];
        if(arr[item] == NULL)
        {
          cerr << "Error: Count not reserve memory for the word size" << endl;
          exit(EXIT_FAILURE);
        }
      }
    }

    ~Stack()
    {
      for(size_t item = 0; item < stack_size; item++)
      {
        delete[] arr[item];
      }
      delete[] arr;
    }

    void push_item(char *word)
    {
      if(num_items == stack_size - 1)
        cout << "Error: Stack overflow." << endl;
      num_items++;
      arr[num_items - 1] = word;
    }

    char* pop_item()
    {
      if(num_items == 0)
        cout << "Error: Stack underflow." << endl;
      char *word = arr[num_items - 1];
      arr[num_items - 1] = NULL;
      num_items--;
      return word;
    }

    bool is_empty()
    {
      if(num_items == 0)
        return true;
      return false;
    }
};

int main()
{
  uint32_t number = 1;

  uint32_t max_word_length = 32;
  uint32_t test_cases = 0;
  cin >> test_cases;
  getchar();

  Stack my_stack(400, max_word_length);

  char c = 'a';
  char *word = NULL;
  uint16_t num_chars = 0;

  c = getchar();
  while(c != EOF && test_cases != 0)
  {
    while(c != ' ' && c != '\n')
    {
      num_chars++;
      word = (char*)realloc(word, num_chars * sizeof(char));
      word[num_chars - 1] = c;
      c = getchar();
    }
    word = (char*)realloc(word, (num_chars + 1) * sizeof(char));
    word[num_chars] = '\0';

    my_stack.push_item(word);

    word = NULL;
    num_chars = 0;

    if(c == '\n')
    {
      cout << "Case #" << number++ << ": ";
      while(my_stack.is_empty() != true)
      {
        word = my_stack.pop_item();
        cout << word << " ";
      }
      cout << endl;
      test_cases--;
      if(test_cases == 0)
        return (EXIT_SUCCESS);
    }

    c = getchar();
  }


  return(EXIT_SUCCESS);
}
