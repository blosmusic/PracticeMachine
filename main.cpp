//
//  main.cpp
//
//  This file is a template to use for C++ in Xcode
//  Code can be entered to use as normal once Csound is in the same directory or imported
//  Note: If importing data from another file make sure to remove Windows commands or add back in if using Windows
//
//  #include "stdafx.h"
//  csoundSetGlobalEnv("OPCODE6DIR64", "C:\\Program Files\\Csound6_x64\\plugins64")
//
//  Created by Benedict Lamb O'Sullivan on 16/11/2019.
//  Copyright © 2019 Benedict Lamb O'Sullivan. All rights reserved.
//
//SECTION A
//This outlines the Csound file and audio settings
//This section does not need to be edited!

//If using Windows add the following line into the code
//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "csound.hpp"
#include <string>
#include <time.h>
#include <stdlib.h>

void introduction(void);
void clear_screen(void);
void beat_finder(void);
void dur_track(void);
void start_met(void);
void bpm_finder(void);
void fin_practice(void);
void options_display(void);
void practice_machine(void);
void practice_options(void);
void interval_practice(void);
void repeat_question(void);
void scale_practice(void);
void scale_question(void);
void key_finder(void);
void play_pearl_jam(void);

int i, j, beat, user_option, user_choice, dur, scale_choice, key,
Major_scale[8] =    {0,2,4,5,7,9,11,12},
dorian_scale[8] =   {0,2,3,5,7,9,10,12},
phy_scale[8] =      {0,1,3,5,7,8,10,12},
Lydian_scale[8] =   {0,2,4,6,7,9,11,12},
Mix_scale[8] =      {0,2,4,5,7,9,10,12},
minor_scale[8]      {0,2,3,5,7,8,10,12},
loc_scale[8] =      {0,1,3,5,6,8,10,12};

float vol, bpm, start = 0,
black_pitches[7] =  {59,60,62,60,59,60,59},
black_note_dur[7] = {.8,.8,.8,.8,.8,.8,1.5};

using namespace std;

    string sco = "";
    //If using Windows add the following line into the code
    //csoundSetGlobalEnv("OPCODE6DIR64", "C:\\Program Files\\Csound6_x64\\plugins64");
    string orc = "sr=44100\n\
    ksmps=32\n\
    nchnls=2\n\
    0dbfs=1\n\
    \n\
    instr 1\n\
    aout oscili p4, cpspch(p5)\n\
    outs aout, aout\n\
    endin\n\
    \n\
    instr 2\n\
    aEnv linen 1, .1, p3, .1\n\
    aout oscili 0.5*aEnv, cpsmidinn(p4)\n\
    outs aout, aout\n\
    endin\n\
    instr 1000\n\
    a1, a2 monitor\n\
    fout \"/Users/benlambosullivan/Desktop/DKIT/Comp Prog/csoundAPI_examples-master 2/cpp/XCode/CsoundAPIExample/CsoundAPIExample/example.wav\", 4, a1, a2\n\
    endin\n\
    schedule(1000, 0, 8)\n\
    ";

int main()
{
//SECTION B
//Code to be entered in the next section.
//Above and below does not change
//CMD B - Build || CMD R - Run
//*********************************************************
//Major Project - CPM - Ben Lamb O'Sullivan
//The following program offers the user some options to aid their personal practice.
//It includes a basic metronome which offers the user a choice over tempo and accenting.
//Options to generate intervals for ear-training or vocal warm ups are included too.
//
std :: cout << ("**********************************************************\n");
std :: cout << ("----- Major Project - CPM - Ben Lamb O'Sullivan -----\n");
std :: cout << ("This programme will offer users options for practicing their instrument.\n");
std :: cout << ("The chosen option will produce a WAV file of the users chosen subject.\n");
std :: cout << ("**********************************************************\n");
//*********************************************************

    practice_machine();


}
//*********************************************************
//SECTION C
//This section lists all functions within the program
//*****Global Function that may be used for a varierty of tasks*****
// fin_pratice() will display the end message for users
    void fin_practice(void)
{
    clear_screen();
    std :: cout << "See You Next Time!\n\n";
}
// repeat_question() will give the user the choice to repeat and action
//local int option_1 is used in these functions as they have no data relevent to further functions
    void repeat_question(void)
{
    clear_screen();
    int option_1;
    std :: cout << "Would you like to practice more? \n\n";
    std :: cout << "Press 1 to continue or any other key to exit.\n\n";
    std :: cin >> option_1;
    switch (option_1)
    {
        case 1: practice_options();
                break;
        case 2: fin_practice();
                break;
    }
}
// clear_screen() will enter blank lines to aid the users experience when interacting with the program
    void clear_screen(void)
{
    int blanklines;
    for (blanklines = 0; blanklines < 30; blanklines++) { cout << "\n"; }
    return;
}
// beat_finder() will be used when user input for accenting beats is required
    void beat_finder(void)
    {

    std :: cout << ("\nWhich beat do you want to accent (1-4)? \n");
    std :: cin >> beat;
    
    beat = beat - 1;
    }
// bpm_finder() will allow the user to input their chosen bpm
    void bpm_finder(void)
{
    std :: cout << ("Which tempo would you like [BPM]? \n");
    std :: cin >> bpm;
    bpm = 60 / bpm;
}
// dur_track() will let the user decide how long to record a sample for
    void dur_track(void)
{
    std :: cout << ("\n\nHow many seconds do you want to record? \n\n");
    std :: cin >> dur;
}
// key_finder() will alow the user to define the key played back
    void key_finder(void)
{
    std :: cout << ("\n\nWhat key would you like to hear?  \n\n");
    std :: cout << "Please select one of the following (1-12): \n\n";
    std :: cout << "01. C\t\t05. E\t\t09. G#\n";
    std :: cout << "02. C#\t\t06. F\t\t10. A\n";
    std :: cout << "03. D\t\t07. F#\t\t11. A#\n";
    std :: cout << "04. D#\t\t08. G\t\t12. B\n\n";
    std :: cin >> key;
    std :: cout << "\n\n";
    switch(key)
    {
        case 1: key = 48;
            break;
        case 2: key = 49;
            break;
        case 3: key = 50;
            break;
        case 4: key = 51;
            break;
        case 5: key = 52;
            break;
        case 6: key = 53;
            break;
        case 7: key = 54;
            break;
        case 8: key = 55;
            break;
        case 9: key = 56;
            break;
        case 10: key = 57;
            break;
        case 11: key = 58;
            break;
        case 12: key = 59;
            break;
    }
}
//*****Metronome Function*****
// start_met() is the function used when the user wants a metronome
    void start_met(void)
{
    beat_finder();
    bpm_finder();
    //dur_track();
    string sco = "";
    for (i = beat; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
        
            if (j == i) { vol = 1; }
            else { vol = .2; }
            sco.append("i1 " + to_string(start) + " " + to_string(.2) + " " + to_string(vol) + " " + to_string(7.00) + "\n");
        
            start = start + bpm;
        }
    }
    
    cout << sco.c_str();

    //create an instance of Csound  sdfr
    Csound* csound = new Csound();

    //set CsOptions
    csound->SetOption("-odac");

    //compile orc
    csound->CompileOrc(orc.c_str());

    //compile sco
    csound->ReadScore(sco.c_str());

    //prepare Csound for performance
    csound->Start();

    //perform entire score
    csound->Perform();

    //free Csound object
    delete csound;
    
    repeat_question();
}
//*****Scale/Mode Decider*****
// scale_question() lets the user pick the desired scale to practice from
void scale_question(void)
{
    clear_screen();
    std :: cout << "What Scale/Mode would you like to practice?\n";
    std :: cout << "Please select one of the following (1-7): \n\n";
    std :: cout << "1. Ionian/Major\n";
    std :: cout << "2. Dorian\n";
    std :: cout << "3. Phrygian\n";
    std :: cout << "4. Lydian\n";
    std :: cout << "5. Mixolydian\n";
    std :: cout << "6. Aeolian/minor\n";
    std :: cout << "7. Locrian\n\n";
    std :: cin >> scale_choice;
}
//*****Interval Practice Function*****
// interval_practice() lets the user practice and listen to random intervals from a defined scale
void interval_practice(void)
{
    //dur_track();
    key_finder();
    string sco = "";
    for ( i = 0; i < 1; i++)
    {
        sco.append("i2 " + to_string(i) + " 1 " + to_string(key + Major_scale[0]) + "\n");
        sco.append("i2 " + to_string(i) + " 1 " + to_string(key + Major_scale[rand ()%8]) + "\n");
    }
    cout << sco.c_str();
    
    //create an instance of Csound  sdfr
    Csound* csound = new Csound();

    //set CsOptions
    csound->SetOption("-odac");

    //compile orc
    csound->CompileOrc(orc.c_str());

    //compile sco
    csound->ReadScore(sco.c_str());

    //prepare Csound for performance
    csound->Start();

    //perform entire score
    csound->Perform();

    //free Csound object
    delete csound;
    
    repeat_question();
}
//*****Scale Functions*****
// scale_practice() allows the user to listen and practice full length scales
void scale_practice(void)
{
    //dur_track();
    key_finder();
    scale_question();
    string sco = "";
    switch(scale_choice)
    {
            case 1:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + Major_scale[i]) + "\n");
                }
            break;
            case 2:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + dorian_scale[i]) + "\n");
                }
            break;
            case 3:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + phy_scale[i]) + "\n");
                }
            break;
            case 4:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + Lydian_scale[i]) + "\n");
                }
            break;
            case 5:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + Mix_scale[i]) + "\n");
                }
            break;
            case 6:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + minor_scale[i]) + "\n");
                }
            break;
            case 7:
                for ( i = 0; i < 8; i++)
                {
                    sco.append("i2 " + to_string(i) + " 1 " + to_string(key + loc_scale[i]) + "\n");
                }
    }
    cout << sco.c_str();
    //create an instance of Csound  sdfr
    Csound* csound = new Csound();

    //set CsOptions
    csound->SetOption("-odac");

    //compile orc
    csound->CompileOrc(orc.c_str());

    //compile sco
    csound->ReadScore(sco.c_str());

    //prepare Csound for performance
    csound->Start();

    //perform entire score
    csound->Perform();

    //free Csound object
    delete csound;
    
    repeat_question();
}
//*****Introduction Functions*****
// info_display will detail the information about this project to the user
    void info_display(void)
{
    int option_1;
    clear_screen();
    std :: cout << "The Practice Machine is the final submisson of Ben Lamb O'Sullivan\n";
    std :: cout << "for the Computer Programming for Musicians module. \n\n";
    std :: cout << "Press 1 to continue or any other key to exit.\n\n";
    std :: cin >> option_1;
    switch (option_1)
    {
        case 1: practice_options();
                break;
        case 2: play_pearl_jam();
                break;
    }
}
// introduction() is the first screen the user will see
    void introduction(void)
{
    std :: cout << "Welcome to the Practice Machine\n";
    std :: cout << "Please select one of the following (1-3): \n\n";
    std :: cout << "1. Information about Program\n";
    std :: cout << "2. Practice\n";
    std :: cout << "3. Finished Practicing\n\n";
    std :: cin >> user_option;
}
// practice_machine() is the welcoming display for users
    void practice_machine(void)
{
    introduction();
    switch (user_option)
    {
        case 1: info_display();
                break;
        case 2: practice_options();
                break;
        case 3: play_pearl_jam();
            fin_practice();
            break;
    }
}
//*****Practice Option Functions*****
// options_display() is the second menu to present the user their choice
void options_display(void)
{
    clear_screen();
    std :: cout << "Here are the Practice Machine's options\n";
    std :: cout << "Please select one of the following (1-3): \n\n";
    std :: cout << "1. Metronome\n";
    std :: cout << "2. Practice Intervals\n";
    std :: cout << "3. Practice Scales\n";
    std :: cout << "4. Finished Practicing\n\n";
    std :: cin >> user_choice;
}
// practice_options() details the users what options are available
    void practice_options(void)
{
    options_display();
    switch (user_choice)
    {
        case 1: start_met();
                break;
        case 2: interval_practice();
                break;
        case 3: scale_practice();
                break;
        case 4: fin_practice();
                break;
    }
}
// play_pearl_jam() is a present as an Easter Egg in the code so that an audio file is created in all situations
    void play_pearl_jam(void)
{
        string sco = "";
        for (i = 0; i < 7; i++)
            {
                sco.append("i2 " + to_string(start) + " " + to_string(black_note_dur[i]) + " " + to_string(black_pitches[i]) + "\n");
                start = start + black_note_dur[i];
            }

        cout << sco.c_str();

        //create an instance of Csound  sdfr
        Csound* csound = new Csound();

        //set CsOptions
        csound->SetOption("-odac");

        //compile orc
        csound->CompileOrc(orc.c_str());

        //compile sco
        csound->ReadScore(sco.c_str());

        //prepare Csound for performance
        csound->Start();

        //perform entire score
        csound->Perform();

        //free Csound object
        delete csound;
}

