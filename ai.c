#include <stdio.h>
#include <string.h>

// Function to get a response based on user input
const char* getResponse(const char* userInput) {
    if (strstr(userInput, "hello") || strstr(userInput, "hi")) {
        return "Hello! How can I assist you today?";
    } else if (strstr(userInput, "how are you")) {
        return "I'm just a computer program, so I don't have feelings, but thanks for asking!";
    } else if (strstr(userInput, "bye")) {
        return "Goodbye! Have a great day!";
    } else {
        return "I'm sorry, I don't understand. Please ask another question.";
    }
}

int main() {
    char userInput[100];

    printf("AI: Hello! How can I assist you today?\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Remove the newline character
        userInput[strcspn(userInput, "\n")] = '\0';

        if (strcmp(userInput, "exit") == 0) {
            printf("AI: Goodbye! Have a great day!\n");
            break;
        }

        const char* response = getResponse(userInput);
        printf("AI: %s\n", response);
    }

    return 0;
}
