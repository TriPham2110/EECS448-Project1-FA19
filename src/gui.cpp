// -*- C++ -*-
/**
* @file   gui.cpp
* @date   14 September 2019
* @brief
*/

#include "fieldcontainer.h"
#include "mainmenu.h"
#include "gui.h"

UserInterface::UserInterface()
	: Gtk::Box(Gtk::ORIENTATION_VERTICAL)
{
	bootstrap_field_container();
	bootstrap_main_menu();
}

UserInterface::~UserInterface() {
	delete field_container;
	delete main_menu;
}

void UserInterface::bootstrap_field_container() {
	this->field_container = new FieldContainer();
	this->add(*field_container);
	field_container->show();
}

void UserInterface::bootstrap_main_menu() {
	this->main_menu = new MainMenu();
	this->add(*main_menu);
	main_menu->show();
}
