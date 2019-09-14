// -*- C++ -*-
/**
* @file   main_menu.cpp
* @date   13 September 2019
* @brief
*/

#include <iostream>

#include "mainmenu.h"

void MainMenu::MainMenu() {

}

void MainMenu::~MainMenu() {

}

void MainMenu::on_start_button_clicked() {
	std::cout << "Game Started." << std::endl;
}

void MainMenu::on_pause_button_clicked() {
	std::cout << "Game Paused." << std::endl;
}

void MainMenu::on_exit_button_clicked() {
	std::cout << "Exiting game..." << std::endl;
}

void MainMenu::add_start_menu_button_decoration() {
	start_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_start_button_clicked));
	add(start_menu_button);
	start_menu_button.show();
}


void MainMenu::add_pause_menu_button_decoration() {
	pause_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_pause_button_clicked));
	add(pause_menu_button);
	pause_menu_button.show();
}


void MainMenu::add_exit_menu_button_decoration() {
	exit_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &MainMenu::on_exit_button_clicked));
	add(exit_menu_button);
	exit_menu_button.show();
}
