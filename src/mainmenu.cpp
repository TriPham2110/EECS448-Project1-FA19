// -*- C++ -*-
/**
* @file   main_menu.cpp
* @date   13 September 2019
* @brief
*/

#include <iostream>

#include <gtkmm/messagedialog.h>

#include "executive.h"
#include "gui.h"
#include "window.h"
#include "mainmenu.h"

MainMenu::MainMenu()
	: num_ships_dropdown(true), //t: show as dropdown f: show as button
	  start_menu_button("Start"),
	  pause_menu_button("Pause"),
	  exit_menu_button("Exit"),
	  end_turn_menu_button("Finish Turn"),
	  start_turn_menu_button("Start Turn")
{
	// Makes every button in the menu the same size
	this->set_homogeneous(true);
	// Adds buttons to the menu
	this->add_start_menu_button_decoration();
	this->add_start_turn_menu_button_decoration();
	this->add_end_turn_menu_button_decoration();
	this->add_num_ships_dropdown_decoration();
	this->add_pause_menu_button_decoration();
	this->add_exit_menu_button_decoration();
	// Set the active item to "Choose a Ship"
	this->num_ships_dropdown.set_active_id("0");
}

MainMenu::~MainMenu() {

}

void MainMenu::on_start_button_clicked() {
	if(Executive::get_executive_object()->get_turn_count() == 0) {
		Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
	}
	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		std::cout << "User requests new game... are they sure?" << std::endl;
		switch(confirm_new_game_popup()) {
			case(Gtk::RESPONSE_OK): {
				std::cout << "User chose to start new game. Hiding board and asking other user..." << std::endl;
				int current_player = Executive::get_executive_object()->which_player_is_up();
				switch(current_player) {
					default: break;
					case 0: {
						std::cout << "Player 1 is up. Hiding their board." << std::endl;
						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(0);
						break;
					}
					case 1: {
						std::cout << "Player 2 is up. Hiding their board." << std::endl;
						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(0);
						break;
					}
				}
				switch(confirm_new_game_popup()) {
					case(Gtk::RESPONSE_OK): {
						std::cout << "Other player agreed to restart. Congratulations!" << std::endl;
						Executive::get_executive_object()->set_turn_counter(0);
						Executive::get_executive_object()->set_game_in_progress_state(0);
						break;
					}
					case(Gtk::RESPONSE_CANCEL): {
						std::cout << "Other player declined to restart. Sorry, $PLAYER." << std::endl;
						switch(current_player) {
							default: break;
							case 0: {
								std::cout << "Player 1 is up. Hiding their board." << std::endl;
								Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
								break;
							}
							case 1: {
								std::cout << "Player 2 is up. Hiding their board." << std::endl;
								Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
								break;
							}
						}
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
		Executive::get_executive_object()->set_ship_count(MainMenu::get_result_from_ship_dropdown());
		std::cout << "Using " << MainMenu::get_result_from_ship_dropdown() << " ships." << std::endl;
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
	switch(confirm_exit_popup()) {
		case(Gtk::RESPONSE_OK): {
			std::cout << "Exiting game..." << std::endl;
			Executive::get_executive_object()->quit();
			break;
		}
		case(Gtk::RESPONSE_CANCEL): {
			std::cout << "Cancelling..." << std::endl;
			break;
		}
		default: break;
	}
}

void MainMenu::on_start_turn_button_clicked() {
	std::cout << "Turn: " << Executive::get_executive_object()->get_turn_count() << std::endl;
	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		if(Executive::get_executive_object()->is_a_turn_active()) {
			std::cout << "Turn already in progress." << std::endl;
		} else {
			int current_player = Executive::get_executive_object()->which_player_is_up();
			switch(current_player) {
				default: break;
				case 0: {
					std::cout << "Starting Player 1's turn..." << std::endl;
					Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
					break;
				}
				case 1: {
					std::cout << "Starting Player 2's turn..." << std::endl;
					Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
					break;
				}
			}
			Executive::get_executive_object()->set_turn_active(1);
		}
	} else {
		std::cout << "No game in progress; cannot start turn." << std::endl;
	}
}

void MainMenu::on_end_turn_button_clicked() {
	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		std::cout << "Showing change player popup..." << std::endl;
		int current_player = Executive::get_executive_object()->which_player_is_up();
		switch(current_player) {
			default: break;
			case 0: {
				std::cout << "Player 1 is up. Hiding their board." << std::endl;
				Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(0);
				break;
			}
			case 1: {
				std::cout << "Player 2 is up. Hiding their board." << std::endl;
				Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(0);
				break;
			}
		}
		switch(confirm_switch_players_popup()) {
			case(Gtk::RESPONSE_OK): {
				if(Executive::get_executive_object()->which_player_is_up() == 0) {
					std::cout << "Changing players (1 to 2)" << std::endl;
					Executive::get_executive_object()->set_which_player(1);
				} else {
					std::cout << "Changing players (2 to 1)" << std::endl;
					Executive::get_executive_object()->set_which_player(0);
				}
				Executive::get_executive_object()->set_turn_active(0);
				break;
			}
			case(Gtk::RESPONSE_CANCEL): {
				switch(current_player) {
					default: break;
					case 0: {
						std::cout << "Oh nevermind. Putting Player 1's board back." << std::endl;
						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
						break;
					}
					case 1: {
						std::cout << "Oh nevermind. Putting Player 2's board back." << std::endl;
						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
						break;
					}
				}
				std::cout << "User chose to continue; nevermind..." << std::endl;
				break;
			}
			default: {
				std::cout << "Wait a minute! How did you trigger this?" << std::endl;
				break;
			}
		}
		Executive::get_executive_object()->increment_turn_count();
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

void MainMenu::add_start_turn_menu_button_decoration() {
	start_turn_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_start_turn_button_clicked));
	this->add(start_turn_menu_button);
	start_turn_menu_button.show();
}

void MainMenu::add_end_turn_menu_button_decoration() {
	end_turn_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_end_turn_button_clicked));
	this->add(end_turn_menu_button);
	end_turn_menu_button.show();
}

void MainMenu::add_num_ships_dropdown_decoration() {
	num_ships_dropdown.append("0", "Choose number of ships");
	num_ships_dropdown.append("1", "1 Ship");
	num_ships_dropdown.append("2", "2 Ships");
	num_ships_dropdown.append("3", "3 Ships");
	num_ships_dropdown.append("4", "4 Ships");
	num_ships_dropdown.append("5", "5 Ships");
	this->add(num_ships_dropdown);
	num_ships_dropdown.show();
}

int MainMenu::confirm_new_game_popup() {
	Gtk::MessageDialog dialog("Restart Game?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Ok' to discard game and start anew; 'Cancel' to continue.");
	return dialog.run();
}

int MainMenu::confirm_switch_players_popup() {
	Gtk::MessageDialog dialog("End turn and switch players?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Ok' to switch; 'Cancel' to continue.");
	return dialog.run();
}

int MainMenu::confirm_exit_popup() {
	Gtk::MessageDialog dialog("Are you sure you want to exit?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Yes' to EXIT; 'No' to CONTINUE.");
	return dialog.run();
}

int MainMenu::get_result_from_ship_dropdown() {
	int num_ships_to_play = std::stoi(num_ships_dropdown.get_active_id());
	if(num_ships_to_play == 0) {
		return 1;
	}
	return num_ships_to_play;
}
