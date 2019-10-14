// -*- C++ -*-
/**
* @file   main_menu.cpp
* @date   13 September 2019
* @brief
*/

#include <iostream>

#include <gtkmm/messagedialog.h>

#include "executive.h"
#include "player.h"
#include "board.h"
#include "gui.h"
#include "window.h"
#include "mainmenu.h"

MainMenu::MainMenu()
	: num_ships_dropdown(true), //t: show as dropdown f: show as button
	  start_menu_button("Start/Restart"),
	  exit_menu_button("Exit")
	  //end_turn_menu_button("Finish Turn"),
	  //start_turn_menu_button("Start Turn")
{
	// Makes every button in the menu the same size
	this->set_homogeneous(true);
	//Makes it so the buttons can be vertical

	// Adds buttons to the menu
	this->add_start_menu_button_decoration();
	std::cout<<"\n\n";
  //this->add_start_turn_menu_button_decoration();
	//this->add_end_turn_menu_button_decoration();
	this->add_num_ships_dropdown_decoration();
	std::cout<<"\n\n";
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

		switch(confirm_new_game_popup()) {
			case(Gtk::RESPONSE_OK): {

				int current_player = Executive::get_executive_object()->which_player_is_up();
				switch(current_player) {
					default: break;
					case 0: {

						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(0);
						break;
					}
					case 1: {

						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(0);
						break;
					}
				}
				switch(confirm_new_game_popup()) {
					case(Gtk::RESPONSE_OK): {

						Executive::get_executive_object()->set_turn_counter(0);
						Executive::get_executive_object()->set_game_in_progress_state(0);
						break;
					}
					case(Gtk::RESPONSE_CANCEL): {

						switch(current_player) {
							default: break;
							case 0: {

								Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
								break;
							}
							case 1: {

								Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
								break;
							}
						}
						break;
					}
					default: {

						break;
					}
				}
				break;
			}
			case(Gtk::RESPONSE_CANCEL): {

				break;
			}
			default: {

				break;
			}
		}
	} else {

		Executive::get_executive_object()->set_ship_count(MainMenu::get_result_from_ship_dropdown());

		Executive::get_executive_object()->set_game_in_progress_state(1);
	}
}


void MainMenu::on_exit_button_clicked() {

		Executive::get_executive_object()->quit();

}

/*void MainMenu::on_start_turn_button_clicked() {

	if(Executive::get_executive_object()->get_game_in_progress_state()) {
		if(Executive::get_executive_object()->is_a_turn_active()) {

		} else {
			int current_player = Executive::get_executive_object()->which_player_is_up();
			switch(current_player) {
				default: break;
				case 0: {

					Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
					break;
				}
				case 1: {

					Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
					break;
				}
			}
			Executive::get_executive_object()->set_turn_active(1);
		}
	} else {

	}
}
*/
/*
void MainMenu::on_end_turn_button_clicked() {
	if(Executive::get_executive_object()->get_game_in_progress_state()) {

		int current_player = Executive::get_executive_object()->which_player_is_up();
		switch(current_player) {
			default: break;
			case 0: {

				Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(0);
				break;
			}
			case 1: {

				Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(0);
				break;
			}
		}
		switch(confirm_switch_players_popup()) {
			case(Gtk::RESPONSE_OK): {
				if(Executive::get_executive_object()->which_player_is_up() == 0) {

					Executive::get_executive_object()->set_which_player(1);
					Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
					Executive::get_executive_object()->get_main_window()->get_user_interface()->get_player_two()->get_player_field()->clear_labels();
					Executive::get_executive_object()->get_main_window()->get_user_interface()->get_player_two()->get_status_field()->scan_for_a_hit();
				} else {

					Executive::get_executive_object()->set_which_player(0);
					Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
					Executive::get_executive_object()->get_main_window()->get_user_interface()->get_player_one()->get_player_field()->clear_labels();
					Executive::get_executive_object()->get_main_window()->get_user_interface()->get_player_one()->get_status_field()->scan_for_a_hit();
				}
				Executive::get_executive_object()->set_turn_active(0);
				break;
			}
			case(Gtk::RESPONSE_CANCEL): {
				switch(current_player) {
					default: break;
					case 0: {

						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_ones_board(1);
						break;
					}
					case 1: {

						Executive::get_executive_object()->get_main_window()->get_user_interface()->toggle_player_twos_board(1);
						break;
					}
				}

				break;
			}
			default: {

				break;
			}
		}
		Executive::get_executive_object()->increment_turn_count();
	} else {

	}
}*/

void MainMenu::add_start_menu_button_decoration() {
	start_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_start_button_clicked));
	this->add(start_menu_button);
	//button = start_menu_button;
	//gtk_container_add (GTK_CONTAINER (buttonbox), button);
	start_menu_button.show();
}



void MainMenu::add_exit_menu_button_decoration() {
	exit_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_exit_button_clicked));
	this->add(exit_menu_button);
	//button = exit_menu_button;
	//gtk_container_add (GTK_CONTAINER (buttonbox), button);
	exit_menu_button.show();
}

/*void MainMenu::add_start_turn_menu_button_decoration() {
	start_turn_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_start_turn_button_clicked));
	this->add(start_turn_menu_button);
	start_turn_menu_button.show();
}*/

/*void MainMenu::add_end_turn_menu_button_decoration() {
	end_turn_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_end_turn_button_clicked));
	this->add(end_turn_menu_button);
	end_turn_menu_button.show();
}*/

void MainMenu::add_num_ships_dropdown_decoration() {
	num_ships_dropdown.append("0", "1 Ship");
	num_ships_dropdown.append("1", "2 Ships");
	num_ships_dropdown.append("2", "3 Ships");
	num_ships_dropdown.append("3", "4 Ships");
	num_ships_dropdown.append("4", "5 Ships");
	this->add(num_ships_dropdown);
	//button = num_ships_dropdown;
	//gtk_container_add (GTK_CONTAINER (buttonbox), button);
	num_ships_dropdown.show();
}

int MainMenu::confirm_new_game_popup() {
	Gtk::MessageDialog dialog("Restart Game?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Ok' to discard game and start anew; 'Cancel' to continue.");
	return dialog.run();
}
/*
int MainMenu::confirm_switch_players_popup() {
	Gtk::MessageDialog dialog("End turn and switch players?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Ok' to switch; 'Cancel' to continue.");
	return dialog.run();
}*/

/*int MainMenu::confirm_exit_popup() {
	Gtk::MessageDialog dialog("Are you sure you want to exit?",false,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL,false);
	dialog.set_secondary_text("'Yes' to EXIT; 'No' to CONTINUE.");
	return dialog.run();
}*/

int MainMenu::get_result_from_ship_dropdown() {
	int num_ships_to_play = std::stoi(num_ships_dropdown.get_active_id());
	if(num_ships_to_play == 0) {
		return 1;
	}
	return num_ships_to_play;
}
