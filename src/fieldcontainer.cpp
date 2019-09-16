// -*- C++ -*-
/**
* @file   fieldcontainer.cpp
* @date   13 September 2019
* @brief
*/

#include "fieldcontainer.h"

FieldContainer::FieldContainer()
	: Gtk::Box(Gtk::ORIENTATION_HORIZONTAL)
{
	add_the_players_area();
	add_the_status_area();
}

FieldContainer::~FieldContainer() {

}


void FieldContainer::add_the_players_area() {
	this->player_field = new PlayingField("Field 1");
	this->playing_field_container->pack_start(*player_field);
	player_field->show();
}

void FieldContainer::add_the_status_area() {
	this->status_field = new PlayingField("Field 2");
	this->playing_field_container->pack_start(*status_field);
	status_field->show();
}
