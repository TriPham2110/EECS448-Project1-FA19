// -*- C++ -*-
/**
* @file   main_menu.cpp
* @date   13 September 2019
* @brief
*/

#include <iostream>

#include "mainmenu.h"

MainMenu::MainMenu()
	: start_menu_button("Start"),
	  pause_menu_button("Pause"),
	  exit_menu_button("Exit")
{
	// Makes every button in the menu the same size
	this->set_homogeneous(true);

	// Adds buttons to the menu
	this->add_start_menu_button_decoration();
	this->add_pause_menu_button_decoration();
	this->add_exit_menu_button_decoration();
}

MainMenu::~MainMenu() {

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
