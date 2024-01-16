# 42-minishell

## Subject
The goal of this project is to implement a simple version of _Bash_ using C as programming language. Sounds it easy right? Well, it was a challenge:
- Work with a partner, share ideas, organize, take decision together and accept different approaches and different code.
- Understand the original behaviour of _Bash_, like builtin commands, piping, forking, environment management, redirections, signals handling etc.
- Learn what is a lexer and what is a parser to make the life easier.
- Take decision about the flow of the programm, how to organize the data, keeping the code clean, debuggable and readable from the other team mate.
- Set a limit to the implementation, since this is not well defined in the subject, and the risk to go over and find yourself to implement an infinite version of _Bash_ is high.
- Do the above things with C, respecting the requirements of the subject, the _Norm_ (guidelines to write the code, which must be respected in order to succed the evaluation) of 42 school and without losing any hope. And for sure, NO MEMORY LEAKS ALLOWED!

## The structure
The shell consists in a while loop which should end only in 2 cases (a part of system calls failure, which lead to `exit()` directly):
1) executing *exit* command, a built-in which needs to be re-implemented
2) pressing *ctrl+d*, which means send an end-of-file to `readline()`

Before the loop, an environment is set up copying the environment recieved from the system in which _minishell_ is invoked. To handle the environment we choosed to use _linked-lists_ as structure, and:
<<ADD CODE>>

The loop consists in those well defined steps:
1) _readline()_ waits for the user's input, which is sent to the _lexer_ (if the input was not `exit` or `ctrl+d` was pressed).
2) The _lexer_  <<ADD REFERENCE>> analyzes the input and organizes it in a linked-list of tokens, which are passed to the _parser_.
3) The _parser_ re-organize the tokens, dividing them into nodes, which can be either of type of `IS_PIPE` or `IS_CMD`, and bulding the so-called _syntax tree_.
<<ADD CODE>>
4) Right after parsing, the _expansion_ of the environment variables is performed, and after it, the so called _quote removal_ step. Why? Because _Bash_ does it! <<ADD REFERENCE>>
5) Before passing the result to the execution, we resolved the _here doc_ redirection, using temporary files to hold the content input by the user.
6) Everything is now ready to be sent to the _executor_, which doesn't simply execute, but verifies if the commands to be executed are builtins, it forks children if needed, redirects the input and the output and collect the exit code of the last executed command.

## Decisions
As said, a crucial part of the project was taking decision avoiding to find ourselves in a non-return situation, better said, in a situation in which we had to re-write everything from scratch.

### The whole structure
Decide the whole structure which holds the data, and decide the flow of the program was not an easy job. We did everything step-by-step, trying to maintain the things flexible, without knowing exactly where those steps would have lead us to. For example, I initially decided to organize the environment using _double-linked lists_, but I discovered then that was not really necessary and more prone error instead of using something more simple ("keep it simple!" they said). Another thing that took us a lot of time to figure out, was the _expansion_ and _quote removal_, since we were not aware of the existence second step (_RTFM_ <<ADD REFERENCE>> story). This because I wrote the first version, then I wrote a second one which wa completely a mess, and then returned to the first, discovering that to achieve the desired result wa "easier" than expected.

### Abstract Syntax Tree VS Command Table
After talking with people who already made the project, I finally reach my absolute personal opinion that an _Abstract Syntax Tree_ <<ADD REFERENCE>> is not necessary, but it is just a different way to organize the data. A lot of mates, we included, used the _AST_ just for learning pourposes. The difficulty about choosing it as a data holder, was that we used nodes with `void *` content, which needed to be casted any time we wanted to use it. An alternative was to use `union`, but because of its particularity in memory management <<ADD REFERENCE>> we preferred the first mentioned approach.

### How much go deep
This was personally pretty problematic. Since for me the precision was important, I pressed to make the things very detailed. In this list, the first thing to mention is the _expansion_ and _quote removal_, which is the main reason that gave us a final point of `101` instead of `100` (yes, you read correctly, is not a joke). Other side features were: handling of `$OLDPWD`, `$SHELL` variables and `NULL` environment; sorting the environment in case of `export` builtin; append a content of a variable in case of operator `+=` like `export user+=hello`; same behaviour of bash in case of sending signal with `ctrl+c` in case of here doc; clean `exit()` in each potential case of system call failure, for example protectig each `malloc()`. I had probably other multiple WONDERFUL ideas, but fortunately my team mate stopped me and bring me to the reality (thanks <<ADD USER>>).

## Bugs
We passed ALL the tests with success and no bugs was found during our evaluation, but we know about very small stuff which doesn't work as expected (or better said, as bash).
- This following test behaves differently from bash.
<<ADD TEST>>
- `echo -nnnnnnn HelloWorld` works differently.
- `/bin/echo` with multiple quoted arguments has different results, because it's an original command which uses a non-original lexer and parser.
- NO cases in which the program crashes is known.

So, if you can find other bugs, I would be happy to update this list without without any worries, because until this point we know that we have already done a very good work.
