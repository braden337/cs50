# Problem Set 1: C

- [Smart Water](#smart-water)
- [Itsa Mario](#itsa-mario)
  - [Less Comfortable](#less-comfortable)
  - [More Comfortable](#more-comfortable)
- [Fun With Algorithms](#fun-with-algorithms)
  - [Greedy](#less-comfortable-1)
  - [Credit](#more-comfortable-1)

If you haven't already, do review the course's policy on academic honesty in
the syllabus on the course's website.

## tl;dr

  0. Watch [Week 1's lecture](https://video.cs50.net/2016/fall/lectures/1).

  1. Say hello with `hello.c`.

  2. Calculate your water usage with with `water.c`.

  3. Build one of Mario's pyramids in `mario.c`.

  4. Implement a "greedy algorithm" in `greedy.c` or a "checksum" in `credit.c`.

  5. Submit a form.

## Help

For help with Week 1 and Problem Set 1:

  * Attend David's walkthrough on Wed 9/7, 1pm – 2:30pm, in Sanders.

  * Watch Zamyla's walkthroughs herein.

  * Attend one of Week 1's course-wide sections (aka supersections):

    * Wed 9/7, 2:30pm – 4pm, in Emerson 210 for those less comfortable (and somewhere in between)

    * Wed 9/7, 4:30pm – 6pm, in Emerson 2010 for those more comfortable (and somewhere in between)

  * Post questions and search answers in [CS50 Discuss](http://cs50.net/discuss).

  * Attend office hours, per the schedule on the course's website.

## Getting Started

Recall that CS50 IDE is a web-based "integrated development environment" that
allows you to program "in the cloud," without installing any software locally.
Underneath the hood is a popular operating system, Ubuntu Linux, that's been
"containerized" with open-source software called Docker, that allows multiple
users (like you!) to share the operating system's "kernel" (its nucleus, so to
speak) and files, even while having files of their own. Indeed, CS50 IDE
provides you with your very own "workspace" (i.e., storage space) in which you
can save your own files and folders (aka directories).

### Logging In

Head to [cs50.io](https://cs50.io/) and log into CS50 IDE. You may be prompted
(again) for your email address. If so, after providing it, click **Private**
under **Hosted workspace**, then click **Create workspace**.

You should then be informed that CS50 IDE (aka Cloud9, the software that
underlies CS50 IDE) is "creating your workspace" and "creating your
container," which might take a moment. You should eventually see your
workspace, which should resemble mine from Week 1. If not, do just email the
course's heads to inquire!

### Updating

Toward the bottom of CS50 IDE's UI is a "terminal window" (light blue, by
default), a command-line interface (CLI) that allows you to explore your
workspace's files and directories, compile code, run programs, and even
install new software. You should find that its "prompt" resembles the below.

    
    
    ~/workspace/ $

Click inside of that terminal window and then type

    
    
    update50

followed by Enter to ensure that your workspace is up-to-date. It might take a
few minutes for any updates to complete. (Be sure not to close the tab or CS50
IDE itself until they do!)

### Hello

Okay, let's create a folder in which your code for this problem set will soon
live. Toward CS50 IDE's top-left corner, you should see a little folder called
**~/workspace** in which all of your work will (soon!) live. Control-click or
right-click that folder and select **New Folder**. A new folder called **New
Folder** should appear; rename it **pset1**, then hit Enter. (If you misname
it or can't seem to edit its name, control-click or right-click the new folder
and select **Rename** to try again!)

Next, control-click or right-click that **pset1** folder that you just created
and select **New File**. A new file called **Untitled** should appear; rename
it **hello.txt** (all lowercase) and then hit Enter. (If you misname it or
can't seem to edit its name, control-click or right-click the new file and
select **Rename** to try again!) You should see that **hello.txt** is indented
immediately beneath **pset1**, which indicates that the former is inside of
the latter. If **hello.txt** doesn't appear to be inside of **pset1**, simply
drag and drop the former into the latter.

Double-click **hello.txt**, and a new tab should appear within CS50 IDE via
which you can edit the file. Go ahead and type something simple (e.g., `hello`
or the ever-popular `asdf`). Notice that red dot should then appear atop the
tab, to the right of the tab's name. That red dot indicates that your file has
changed but not yet been saved. Go ahead and save the file via **File > Save**
or, more quickly, via command-S (on Macs) or control-S (on PCs). The asterisk
should disappear.

Okay, now let's confirm via your terminal window that the file is indeed where
it should be and start to familiarize you with that terminal window's command-
line interface. As before, your terminal window's prompt should be the below.

    
    
    ~/workspace/ $

That prompt indicates that `workspace` is the name of your terminal window's
"current working directory" (i.e., the folder that's currently open within
that command-line environment). The tilde (`~`), meanwhile, refers to your
account's "home directory," in which your `workspace` directory lives, but
more on that another time. As you might have guessed, this `workspace`
directory is identical to that **~/workspace** folder in CS50 IDE's top-left
corner.

Okay, let's poke around. Again click somewhere inside of that terminal window
and then type

    
    
    ls

followed by Enter. That's a lowercase L and a lowercase S, which is shorthand
notation for "list." Indeed, you should then see a list of the folders inside
of your workspace, among which is `pset1`! Let's open that folder. Type

    
    
    cd pset1

or even, more verbosely,

    
    
    cd ~/workspace/pset1/

followed by Enter to change your directory to `~/workspace/pset1` (ergo,
`cd`). You should find that your prompt changes to

    
    
    ~/workspace/pset1/ $

confirming that you are indeed now inside of `~/workspace/pset1/` (i.e., a
directory called `pset1` inside of a directory called `workspace` inside of
your home directory). Now type

    
    
    ls

followed by Enter. You should see `hello.txt`! Now, you can't click or double-
click on that file's name there; it's just text. But that listing does confirm
that `hello.txt` is where we hoped it would be. (If not, take another stab at
these steps or simply ask classmates or staff for some help!)

Let's poke around a bit more. Go ahead and type

    
    
    cd

and then Enter. If you don't provide `cd` with a "command-line argument"
(i.e., a directory's name), it whisks you back to your workspace by default.
Indeed, your prompt should now be

    
    
    ~/workspace/ $

again. To get back into `pset1`, type

    
    
    cd pset1/

and then Enter. Make sense? If not, no worries; it soon will! It's in this
terminal window that you'll soon be compiling your first program!

## Hello, C

First, a hello from Zamyla if you'd like a tour of what's to come,
particularly if less comfortable.

[![Hello](https://img.youtube.com/vi/vbkTzOytISY/0.jpg)](https://www.youtube.com/watch?v=vbkTzOytISY)

Shall we have you write your first program? Inside of your **pset1** folder,
create a new file called **hello.c**, and then open that file in a tab.
(Remember how?) Be sure to capitalize the file's name just as we have; files'
and folders' names in Linux are "case-sensitive." Proceed to write your first
program by typing precisely these lines into the file:

    
    
    #include <stdio.h>
    
    int main(void)
    {
        printf("Hello, world!\n");
    }

Notice how CS50 IDE adds "syntax highlighting" (i.e., color) as you type,
though CS50 IDE's choice of colors might differ from this problem set's. Those
colors aren't actually saved inside of the file itself; they're just added by
CS50 IDE to make certain syntax stand out. Had you not saved the file as
`hello.c` from the start, CS50 IDE wouldn't know (per the filename's
extension) that you're writing C code, in which case those colors would be
absent.

Do be sure that you type this program just right, else you're about to
experience your first bug! In particular, capitalization matters, so don't
accidentally capitalize words (unless they're between those two quotes). And
don't overlook that one semicolon. C is quite nitpicky!

When done typing, select **File > Save** (or hit command- or control-s), but
don't quit. Recall that the leading asterisk in the tab's name should then
disappear. Click anywhere in the terminal window beneath your code, and be
sure that you're inside of `~/workspace/pset1/`. (Remember how? If not, type
`cd` and then Enter, followed by `cd workspace/pset1/` and then Enter.) Your
prompt should be:

    
    
    ~/workspace/pset1/ $

Let's confirm that `hello.c` is indeed where it should be. Type

    
    
    ls

followed by Enter, and you should see both `hello.c` and `hello.txt`? If not,
no worries; you probably just missed a small step. Best to restart these past
several steps or ask for help!

Assuming you indeed see `hello.c`, let's try to compile! Cross your fingers
and then type

    
    
    make hello

at the prompt, followed by Enter. (Well, maybe don't cross your fingers whilst
typing.) To be clear, type only `hello` here, not `hello.c`. If all that you
see is another, identical prompt, that means it worked! Your source code has
been translated to object code (0s and 1s) that you can now execute. Type

    
    
    ./hello

at your prompt, followed by Enter, and you should see the below:

    
    
    Hello, world!

And if you type

    
    
    ls

followed by Enter, you should see a new file, `hello`, alongside `hello.c` and
`hello.txt`. The first of those files, `hello`, should have an asterisk after
its name that, in this context, means it's "executable," a program that you
can execute (i.e., run).

If, though, upon running `make`, you instead see some error(s), it's time to
debug! (If the terminal window's too small to see everything, click and drag
its top border upward to increase its height.) If you see an error like
"expected declaration" or something just as mysterious, odds are you made a
syntax error (i.e., typo) by omitting some character or adding something in
the wrong place. Scour your code for any differences vis-à-vis the template
above. It's easy to miss the slightest of things when learning to program, so
do compare your code against ours character by character; odds are the
mistake(s) will jump out! Anytime you make changes to your own code, just
remember to re-save via **File > Save** (or command- or control-s), then re-
click inside of the terminal window, and then re-type

    
    
    make hello

at your prompt, followed by Enter. (Just be sure that you are inside of
`~/workspace/pset1/` within your terminal window, as your prompt will confirm
or deny.) If still seeing errors, try "prepending" `help50` to your command
like this:

    
    
    help50 make hello

That'll pass the output of `make hello` to a program called `help50`, which
CS50's staff wrote. If `help50` recognizes your error message, it'll offer
some suggestions (in yellow). Just realize `help50` is new this year, so odds
are it won't recognize all error messages just yet!

Once you see no more errors, try "executing" (i.e., running) your program by
typing

    
    
    ./hello

at your prompt, followed by Enter! Hopefully you now see whatever you told
`printf` to print?

If not, reach out for help! Incidentally, if you find the terminal window too
small for your tastes, know that you can open one in a bigger tab by clicking
the circled plus (+) icon to the right of your `hello.c` tab.

## CS50 Check

Now let's see if the program you just wrote is correct! Included in CS50 IDE
is `check50`, a command-line program with which you can check the correctness
of (some of) your programs.

If not already there, navigate your way to `~/workspace/pset1/` by executing
the command below.

    
    
    cd ~/workspace/pset1/

If you then execute

    
    
    ls

you should see, at least, `hello.c`. Be sure it's indeed spelled `hello.c` and
not `Hello.c`, `hello.C`, or the like. If it's not, know that you can rename a
file by executing

    
    
    mv source destination

where `source` is the file's current name, and `destination` is the file's new
name. For instance, if you accidentally named your program `Hello.c`, you
could fix it as follows.

    
    
    mv Hello.c hello.c

Okay, assuming your file's name is definitely spelled `hello.c` now, go ahead
and execute the below. Note that `2016.hello` is just a unique identifier for
this problem's checks.

    
    
    check50 2016.hello hello.c

Assuming your program is correct, you should then see output like

    
    
    :) hello.c exists
    :) hello.c compiles
    :) prints "Hello, world!\n"

where each green smiley means your program passed a check (i.e., test). You
may also see a URL at the bottom of `check50`'s output, but that's just for
staff (though you're welcome to visit it).

If you instead see yellow or red smileys, it means your code isn't correct!
For instance, suppose you instead see the below.

    
    
    :( hello.c exists
      \ expected hello.c to exist
    :| hello.c compiles
      \ can't check until a frown turns upside down
    :| prints "Hello, world!\n"
      \ can't check until a frown turns upside down

Because `check50` doesn't think `hello.c` exists, as per the red smiley, odds
are you uploaded the wrong file or misnamed your file. The other smileys,
meanwhile, are yellow because those checks are dependent on `hello.c`
existing, and so they weren't even run.

Suppose instead you see the below.

    
    
    :) hello.c exists
    :) hello.c compiles
    :( prints "Hello, world!\n"
      \ expected output, but not "Hello, world!"

Odds are, in this case, you printed something other than `Hello, world!\n`
verbatim, per the spec's expectations. In particular, the above suggests you
printed `Hello, world!`, without a trailing newline (`\n`).

Know that `check50` won't actually record your scores in CS50's gradebook.
Rather, it lets you check your work's correctness _before_ you submit your
work. Once you actually submit your work (per the directions at this spec's
end), CS50's staff will use `check50` to evaluate your work's correctness
officially.

## Smart Water

Suffice it to say that the longer you shower, the more water you use. But just
how much? Even if you have a "low-flow" showerhead, odds are your shower spits
out 1.5 gallons of water per minute. A gallon, meanwhile, is 128 ounces, and
so that shower spits out 1.5 × 128 = 192 ounces of water per minute. A typical
bottle of water (that you might have for a drink, not a shower), meanwhile,
might be 16 ounces. So taking a 1-minute shower is akin to using 192 ÷ 16 = 12
bottles of water. Taking (more realistically, perhaps!) a 10-minute shower,
then, is like using 120 bottles of water. Deer Park, that's a lot of water! Of
course, bottled water itself is wasteful; best to use reusable containers when
you can. But it does put into perspective what's being spent in a shower!

Write, in a file called `water.c` in your `~/workspace/pset1/` directory, a
program that prompts the user for the length of his or her shower in minutes
(as a positive integer) and then prints the equivalent number of bottles of
water (as an integer) per the sample output below, wherein underlined text
represents some user's input.

    
    
    ~/workspace/pset1/ $ ./water
    minutes: 10
    bottles: 120

For simplicity, you may assume that the user will input a positive integer, so
no need for error-checking (or any loops) this time! And no need to worry
about overflow!

Recall that, to compile your program, you can execute the below.

    
    
    ~/workspace/pset1/ $ make water

And if you see any error messages you don't understand, try running

    
    
    ~/workspace/pset1/ $ help50 make water

for advice.

If you'd like to check the correctness of your program with `check50`, you may
execute the below.

    
    
    check50 2016.water water.c

If unsure how to begin, here's Zamyla.

[![Water](https://img.youtube.com/vi/oAcVHgmjTHE/0.jpg)](https://www.youtube.com/watch?v=oAcVHgmjTHE)

And if you'd like to play with the staff's own implementation of `water`
within CS50 IDE, you may execute the below.

    
    
    ~cs50/pset1/water

## Itsa Mario

Implement **one** of the versions of `mario` specified below. Both versions
are worth the same (and there's no extra credit for implementing both!), but
it's entirely up to you which of the two to implement. The overarching goal is
to offer everyone a ceiling that's relative to their own height. Here's some
(non-binding) advice:

  * If among those less comfortable, generally tackle less-comfortable versions of problems but try at least a few more-comfortable problems this term.

  * If among those more comfortable, generally tackle more-comfortable versions of problems unless you really hit a wall with some problem.

  * If among those somewhere in between, tackle less-comfortable versions about half of the time and more-comfortable versions about half of the time.

### Less Comfortable

Toward the end of World 1-1 in Nintendo's Super Mario Brothers, Mario must
ascend a "half-pyramid" of blocks before leaping (if he wants to maximize his
score) toward a flag pole. Below is a screenshot.

Write, in a file called `mario.c` in your `~/workspace/pset1/` directory, a
program that recreates this half-pyramid using hashes (`#`) for blocks.
However, to make things more interesting, first prompt the user for the half-
pyramid's height, a non-negative integer no greater than `23`. (The height of
the half-pyramid pictured above happens to be `8`.) If the user fails to
provide a non-negative integer no greater than `23`, you should re-prompt for
the same again. Then, generate (with the help of `printf` and one or more
loops) the desired half-pyramid. Take care to align the bottom-left corner of
your half-pyramid with the left-hand edge of your terminal window, as in the
sample output below, wherein underlined text represents some user's input.

    
    
    ~/workspace/pset1/ $ ./mario
    height: 8
           ##
          ###
         ####
        #####
       ######
      #######
     ########
    #########

Note that the rightmost two columns of blocks must be of the same height. No
need to generate the pipe, clouds, numbers, text, or Mario himself.

By contrast, if the user fails to provide a non-negative integer no greater
than `23`, your program's output should instead resemble the below, wherein
underlined text again represents some user's input. (Recall that `get_int`
will handle some, but not all, re-prompting for you.)

    
    
    ~/workspace/pset1/ $ ./mario
    Height: -2
    Height: -1
    Height: foo
    Retry: bar
    Retry: 1
    ##

To compile your program, remember that you can execute

    
    
    make mario

after which you can run your program with the below.

    
    
    ./mario

If you encounter any errors you don't understand, try asking `help50` for
help. (Remember how?)

If you'd like to check the correctness of your program with `check50`, you may
execute the below.

    
    
    check50 2016.mario.less mario.c

And if you'd like to play with the staff's own implementation of `mario`
within CS50 IDE, you may execute the below.

    
    
    ~cs50/pset1/mario

Not sure where to begin? Not to worry, here's Zamyla:

[![Mario](https://img.youtube.com/vi/EGWRG5e1O2s/0.jpg)](https://www.youtube.com/watch?v=EGWRG5e1O2s)

### More Comfortable

* * *

Toward the beginning of World 1-1 in Nintendo's Super Mario Brothers, Mario
must hop over two "half-pyramids" of blocks as he heads toward a flag pole.
Below is a screenshot.

Write, in a file called `mario.c` in your `~/workspace/pset1` directory, a
program that recreates these half-pyramids using hashes (`#`) for blocks.
However, to make things more interesting, first prompt the user for the half-
pyramids' heights, a non-negative integer no greater than `23`. (The height of
the half-pyramids pictured above happens to be `4`, the width of each half-
pyramid `4`, with an a gap of size `2` separating them.) Then, generate (with
the help of `printf` and one or more loops) the desired half-pyramids. Take
care to left-align the bottom-left corner of the left-hand half-pyramid, as in
the sample output below, wherein boldfaced text represents some user's input.

    
    
    ~/workspace/pset1/ $ ./mario
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####

No need to generate the bricks, cloud, numbers, or text in the sky or Mario
himself. Just the half-pyramids!

We leave it to you to determine how to compile this program.

If you'd like to play with the staff's own implementation of `mario` within
CS50 IDE, you may execute the below.

    
    
    ~cs50/hacker1/mario

Like to implement these two half-pyramids but not sure how to approach them?
Here's Zamyla with a walkthrough.

[![Mario](https://img.youtube.com/vi/xX7DQGkEG48/0.jpg)](https://www.youtube.com/watch?v=xX7DQGkEG48)

## Fun with Algorithms

Implement **either** `greedy` or `credit` based on your own comfort level.

### Less Comfortable

Ever seen one of these, a "classic coin changer just like [the] ones used by
street vendors and the ice cream truck", which lets you dispense coins by
pressing levers?

When using a device like this, odds are you want to minimize the number of
coins you're dispensing for each customer, lest you have to press levers more
times than are necessary. Fortunately, computer science has given cashiers
everywhere ways to minimize numbers of coins due: greedy algorithms.

According to the National Institute of Standards and Technology (NIST), a
greedy algorithm is one "that always takes the best immediate, or local,
solution while finding an answer. Greedy algorithms find the overall, or
globally, optimal solution for some optimization problems, but may find less-
than-optimal solutions for some instances of other problems."

What's all that mean? Well, suppose that a cashier owes a customer some change
and on that cashier's belt are levers that dispense quarters, dimes, nickels,
and pennies. Solving this "problem" requires one or more presses of one or
more levers. Think of a "greedy" cashier as one who wants to take, with each
press, the biggest bite out of this problem as possible. For instance, if some
customer is owed 41¢, the biggest first (i.e., best immediate, or local) bite
that can be taken is 25¢. (That bite is "best" inasmuch as it gets us closer
to 0¢ faster than any other coin would.) Note that a bite of this size would
whittle what was a 41¢ problem down to a 16¢ problem, since 41 - 25 = 16. That
is, the remainder is a similar but smaller problem. Needless to say, another
25¢ bite would be too big (assuming the cashier prefers not to lose money),
and so our greedy cashier would move on to a bite of size 10¢, leaving him or
her with a 6¢ problem. At that point, greed calls for one 5¢ bite followed by
one 1¢ bite, at which point the problem is solved. The customer receives one
quarter, one dime, one nickel, and one penny: four coins in total.

It turns out that this greedy approach (i.e., algorithm) is not only locally
optimal but also globally so for America's currency (and also the European
Union's). That is, so long as a cashier has enough of each coin, this largest-
to-smallest approach will yield the fewest coins possible.

How few? Well, you tell us. Write, in a file called `greedy.c` in your
`~/workspace/pset1/` directory, a program that first asks the user how much
change is owed and then spits out the minimum number of coins with which said
change can be made. Use `get_float` from the CS50 Library to get the user's
input and `printf` from the Standard I/O library to output your answer. Assume
that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢),
and pennies (1¢).

We ask that you use `get_float` so that you can handle dollars and cents,
albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in
the case where a newspaper costs 25¢ but the customer pays with a $10 bill),
assume that your program's input will be `9.75` and not `$9.75` or `975`.
However, if some customer is owed $9 exactly, assume that your program's input
will be `9.00` or just `9` but, again, not `$9` or `900`. Of course, by nature
of floating-point values, your program will likely work with inputs like `9.0`
and `9.000` as well; you need not worry about checking whether the user's
input is "formatted" like money should be. And you need not try to check
whether a user's input is too large to fit in a `float`. But you should check
that the user's input makes cents! Er, sense. Using `get_float` alone will
ensure that the user's input is indeed a floating-point (or integral) value
but not that it is non-negative. If the user fails to provide a non-negative
value, your program should re-prompt the user for a valid amount again and
again until the user complies.

Incidentally, do beware the inherent imprecision of floating-point values. For
instance, `0.1` cannot be represented exactly as a `float`. Try printing its
value to, say, `55` decimal places, with code like the below:

    
    
    float f = 0.1;
    printf("%.55f\n", f);

And so, before making change, you'll probably want to convert the user's input
entirely to cents (i.e., from a `float` to an `int`) to avoid tiny errors that
might otherwise add up! Of course, don't just cast the user's input from a
`float` to an `int`! After all, how many cents does one dollar equal? And take
care to [round](https://reference.cs50.net/math.h/round) your cents (to the
nearest penny); don't "truncate" (i.e., floor) your cents!

Not sure where to begin? Not to worry, start with a walkthrough:

[![Greedy](https://img.youtube.com/vi/2cArM62sC7E/0.jpg)](https://www.youtube.com/watch?v=2cArM62sC7E)

Incidentally, so that we can automate some tests of your code, we ask that
your program's last line of output be only the minimum number of coins
possible: an integer followed by `\n`. Consider the below representative of
how your own program should behave, wherein underlined text is some user's
input.

    
    
    ~/workspace/pset1/ $ ./greedy
    O hai! How much change is owed?
    0.41
    4

By nature of floating-point values, that user could also have inputted just
`.41`. (Were they to input `41`, though, they'd get many more coins!)

Of course, more difficult users might experience something more like the
below.

    
    
    ~/workspace/pset1 $ ./greedy
    O hai! How much change is owed?
    -0.41
    How much change is owed?
    -0.41
    How much change is owed?
    foo
    Retry: 0.41
    4

Per these requirements (and the sample above), your code will likely have some
sort of loop. If, while testing your program, you find yourself looping
forever, know that you can kill your program (i.e., short-circuit its
execution) by hitting ctrl-c.

We leave it to you to determine how to compile and run this particular
program!

If you'd like to check the correctness of your program with `check50`, you may
execute the below.

    
    
    check50 2016.greedy greedy.c

But if you'd like to play with the staff's own implementation of `greedy`
within CS50 IDE, you may execute the below.

    
    
    ~cs50/pset1/greedy

### More Comfortable

* * *

Odds are you have a credit card in your wallet. Though perhaps the bill does
not (yet) get sent to you! That card has a number, both printed on its face
and embedded (perhaps with some other data) in the magnetic stripe on back.
That number is also stored in a database somewhere, so that when your card is
used to buy something, the creditor knows whom to bill. There are a lot of
people with credit cards in this world, so those numbers are pretty long:
American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and
Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through
9), not binary, which means, for instance, that American Express could print
as many as 10^(15) = 1,000,000,000,000,000 unique cards! (That's, ahem, a
quadrillion.)

Now that's a bit of an exaggeration, because credit card numbers actually have
some structure to them. American Express numbers all start with 34 or 37;
MasterCard numbers all start with 51, 52, 53, 54, or 55; and Visa numbers all
start with 4. But credit card numbers also have a "checksum" built into them,
a mathematical relationship between at least one number and others. That
checksum enables computers (or humans who like math) to detect typos (e.g.,
transpositions), if not fraudulent numbers, without having to query a
database, which can be slow. (Consider the awkward silence you may have
experienced at some point whilst paying by credit card at a store whose
computer uses a dial-up modem to verify your card.) Of course, a dishonest
mathematician could certainly craft a fake number that nonetheless respects
the mathematical constraint, so a database lookup is still necessary for more
rigorous checks.

So what's the secret formula? Well, most cards use an algorithm invented by
Hans Peter Luhn, a nice fellow from IBM. According to Luhn's algorithm, you
can determine if a credit card number is (syntactically) valid as follows:

  0. Multiply every other digit by 2, starting with the number's second-to-last digit, and then add those products' digits together.

  1. Add the sum to the sum of the digits that weren't multiplied by 2.

  2. If the total's last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

That's kind of confusing, so let's try an example with my AmEx:
378282246310005.

  0. For the sake of discussion, let's first underline every other digit, starting with the number's second-to-last digit:

378282246310005

Okay, let's multiply each of the underlined digits by 2:

7•2 + 2•2 + 2•2 + 4•2 + 3•2 + 0•2 + 0•2

That gives us:

14 + 4 + 4 + 8 + 6 + 0 + 0

Now let's add those products' digits (i.e., not the products themselves)
together:

1 + 4 + 4 + 4 + 8 + 6 + 0 + 0 = 27

  1. Now let's add that sum (27) to the sum of the digits that weren't multiplied by 2:

27 + 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 60

  2. Yup, the last digit in that sum (60) is a 0, so Daven's card is legit!

So, validating credit card numbers isn't hard, but it does get a bit tedious
by hand. Let's write a program.

In `credit.c`, write a program that prompts the user for a credit card number
and then reports (via `printf`) whether it is a valid American Express,
MasterCard, or Visa card number, per the definitions of each's format herein.
So that we can automate some tests of your code, we ask that your program's
last line of output be `AMEX\n` or `MASTERCARD\n` or `VISA\n` or `INVALID\n`,
nothing more, nothing less, and that `main` always return `0`. For simplicity,
you may assume that the user's input will be entirely numeric (i.e., devoid of
hyphens, as might be printed on an actual card). But do not assume that the
user's input will fit in an `int`! Best to use `get_long_long` from CS50's
library to get users' input. (Why?)

Consider the below representative of how your own program should behave when
passed a valid credit card number (sans hyphens), wherein underlined text
represents some user's input.

    
    
    ~/workspace/pset1/ $ ./credit
    Number: 378282246310005
    AMEX

Of course, `get_long_long` itself will reject hyphens (and more) anyway:

    
    
    ~/workspace/pset1/ $ ./credit
    Number: 3782-822-463-10005
    Retry: foo
    Retry: 378282246310005
    AMEX

But it's up to you to catch inputs that are not credit card numbers (e.g., a
phone number), even if numeric:

    
    
    ~/workspace/pset1/ $ ./credit
    Number: 6176292929
    INVALID

Test out your program with a whole bunch of inputs, both valid and invalid.
(We certainly will!) Here are a few card numbers that PayPal recommends for
testing:

<https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numb
ers.htm>

Google (or perhaps a roommate's wallet) should turn up more. (If your roommate
asks what you're doing, don't mention us.) If your program behaves incorrectly
on some inputs (or doesn't compile at all), time to debug!

And if you'd like to play with the staff's own implementation of `credit`
within CS50 IDE, you may execute the below.

    
    
    ~cs50/hacker1/credit

Like to tackle this problem but not sure how to begin? Here's Zamyla with a
walkthrough.

[![Credit](https://img.youtube.com/vi/06wNhN54P6k/0.jpg)](https://www.youtube.com/watch?v=06wNhN54P6k)

## How to Submit

_Coming Wed 9/7. Reload this page then!_
