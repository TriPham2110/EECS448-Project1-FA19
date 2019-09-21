// -*- C++ -*-
/**
* @file   main_menu.cpp
* @date   13 September 2019
* @brief
*/

#include <iostream>

#include "executive.h"
#include "mainmenu.h"
#include "changingplayerwindow.h"

MainMenu::MainMenu()
	: num_ships_dropdown("Choose Ships"),
	  start_menu_button("Start"),
	  pause_menu_button("Pause"),
	  exit_menu_button("Exit"),
	  continue_menu_button("Finish Turn")
{
	// Makes every button in the menu the same size
	this->set_homogeneous(true);
	// Adds buttons to the menu
	this->add_continue_menu_button_decoration();
	this->add_start_menu_button_decoration();
	this->add_num_ships_dropdown_decoration();
	this->add_pause_menu_button_decoration();
	this->add_exit_menu_button_decoration();

}

MainMenu::~MainMenu() {

}

void MainMenu::on_start_button_clicked() {
	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		std::cout << "User requests new game... are they sure?" << std::endl;
		switch(confirm_new_game_popup()) {
			case(Gtk::RESPONSE_OK): {
				std::cout << "User chose to start new game. Asking other user..." << std::endl;
				switch(confirm_new_game_popup()) {
					case(Gtk::RESPONSE_OK): {
						std::cout << "Other player agreed to restart. Congratulations!" << std::endl;
						break;
					}
					case(Gtk::RESPONSE_CANCEL): {
						std::cout << "Other player declined to restart. Sorry, $PLAYER." << std::endl;
						break;
					}
					default: {
						std::cout << "No seriously, how are you triggering these?" << std::endl;
						break;
					}
				}
				break;
			}
			case(Gtk::RESPONSE_CANCEL): {
				std::cout << "User chose to continue; nevermind..." << std::endl;
				break;
			}
			default: {
				std::cout << "Wait a minute! How did you trigger this?" << std::endl;
				break;
			}
		}
	} else {
		std::cout << "Game Started." << std::endl;
		Executive::get_executive_object()->set_game_in_progress_state(1);
	}
}

void MainMenu::on_pause_button_clicked() {
	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		if(Executive::get_executive_object()->get_game_paused_state() == 0) {
			Executive::get_executive_object()->set_game_paused_state(1);
			std::cout << "Game paused." << std::endl;
		} else {
			Executive::get_executive_object()->set_game_paused_state(0);
			std::cout << "Game unpaused." << std::endl;
		}
	} else {
		std::cout << "No game to pause." << std::endl;
	}
}

void MainMenu::on_exit_button_clicked() {
	std::cout << "Exiting game..." << std::endl;
}

void MainMenu::on_continue_button_clicked() {
	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		std::cout << "Showing change player popup..." << std::endl;
		switch(confirm_switch_players_popup()) {
			case(Gtk::RESPONSE_OK): {
				if(Executive::get_executive_object()->which_player_is_up() == 0) {
					std::cout << "Changing players (1 to 2)" << std::endl;
					Executive::get_executive_object()->set_which_player(1);
				} else {
					std::cout << "Changing players (2 to 1)" << std::endl;
					Executive::get_executive_object()->set_which_player(0);
				}
				//This will later call the changing players window
				ChangingPlayerWindow* changing_player_window = new ChangingPlayerWindow();
				changing_player_window->show();
				break;
			}
			case(Gtk::RESPONSE_CANCEL): {
				std::cout << "User chose to continue; nevermind..." << std::endl;
				break;
			}
			default: {
				std::cout << "Wait a minute! How did you trigger this?" << std::endl;
				break;
			}
		}
	} else {
		std::cout << "No game in progress: nothing to do." << std::endl;
	}
}

void MainMenu::add_start_menu_button_decoration() {
	start_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_start_button_clicked));
	this->add(start_menu_button);
	start_menu_button.show();
}

void MainMenu::add_pause_menu_button_decoration() {
	pause_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_pause_button_clicked));
	this->add(pause_menu_button);
	pause_menu_button.show();
}

void MainMenu::add_exit_menu_button_decoration() {
	exit_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_exit_button_clicked));
	this->add(exit_menu_button);
	exit_menu_button.show();
}


void MainMenu::add_continue_menu_button_decoration() {
	continue_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_continue_button_clicked));
	this->add(continue_menu_button);
	continue_menu_button.show();
}

void MainMenu::add_num_ships_dropdown_decoration() {
	num_ships_dropdown.append("1 Ship");
	num_ships_dropdown.append("2 Ships");
	num_ships_dropdown.append("3 Ships");
	num_ships_dropdown.append("4 Ships");
	num_ships_dropdown.append("5 Ships");
	this->add(num_ships_dropdown);
	num_ships_dropdown.show();
}

int MainMenu::confirm_new_game_popup() {
	Gtk::MessageDialog dialog("Restart Game?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Yes' to discard game and start anew; 'No' to continue.");
	return dialog.run();
}

int MainMenu::confirm_switch_players_popup() {
	Gtk::MessageDialog dialog("End turn and switch players?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Yes' to switch; 'No' to continue.");
	return dialog.run();
}
