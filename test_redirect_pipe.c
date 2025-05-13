#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc; // Unused parameters
    (void)argv;

    // Test 1: Simple pipeline with redirection
    printf("Test 1: ls -l | grep .c > output.txt\n");

    // Hard-code the first command: ls -l
    char *ls_args[] = {"ls", "-l", NULL};
    t_cmd ls_cmd = {
        .command = "ls",
        .args = ls_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 1, // This command is followed by a pipe
        .next = NULL
    };

    // Hard-code the second command: grep .c > output.txt
    char *grep_args[] = {"grep", ".c", NULL};
    t_cmd grep_cmd = {
        .command = "grep",
        .args = grep_args,
        .input_redirect = NULL,
        .output_redirect = "output.txt", // Redirect output to a file
        .is_background = 0,
        .is_pipe = 0, // This is the last command in the pipeline
        .next = NULL
    };

    // Link the commands together
    ls_cmd.next = &grep_cmd;

    // Execute the pipeline
    execute_pipeline(&ls_cmd, &grep_cmd, envp);

    // Test 2: Input redirection and pipeline
    printf("\nTest 2: wc -l < input.txt | sort -n\n");

    // Hard-code the first command: wc -l < input.txt
    char *wc_args[] = {"wc", "-l", NULL};
    t_cmd wc_cmd = {
        .command = "wc",
        .args = wc_args,
        .input_redirect = "input.txt", // Redirect input from a file
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 1, // This command is followed by a pipe
        .next = NULL
    };

    // Hard-code the second command: sort -n
    char *sort_args[] = {"sort", "-n", NULL};
    t_cmd sort_cmd = {
        .command = "sort",
        .args = sort_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0, // This is the last command in the pipeline
        .next = NULL
    };

    // Link the commands together
    wc_cmd.next = &sort_cmd;

    // Execute the pipeline
    execute_pipeline(&wc_cmd, &sort_cmd, envp);

    // Test 3: Combined input and output redirection
    printf("\nTest 3: grep hello < input.txt > output.txt\n");

    // Hard-code the command: grep hello < input.txt > output.txt
    char *grep_hello_args[] = {"grep", "hello", NULL};
    t_cmd grep_hello_cmd = {
        .command = "grep",
        .args = grep_hello_args,
        .input_redirect = "input.txt",  // Redirect input from a file
        .output_redirect = "output.txt", // Redirect output to a file
        .is_background = 0,
        .is_pipe = 0, // No pipe, standalone command
        .next = NULL
    };

    // Execute the command (no pipeline, just redirection)
    execute_pipeline(&grep_hello_cmd, &grep_hello_cmd, envp);

    // Free the command nodes (if dynamically allocated)
    // free_cmd_node(&ls_cmd);         // Uncomment if using dynamic allocation
    // free_cmd_node(&grep_cmd);       // Uncomment if using dynamic allocation
    // free_cmd_node(&wc_cmd);         // Uncomment if using dynamic allocation
    // free_cmd_node(&sort_cmd);       // Uncomment if using dynamic allocation
    // free_cmd_node(&grep_hello_cmd); // Uncomment if using dynamic allocation

    return 0;
}