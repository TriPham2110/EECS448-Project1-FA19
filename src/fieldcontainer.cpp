// -*- C++ -*-
/**
* @file   fieldcontainer.cpp
* @date   13 September 2019
* @brief
*/

#include "fieldcontainer.h"
#include "field.h"

FieldContainer::FieldContainer()
	: Gtk::Box(Gtk::ORIENTATION_HORIZONTAL)
{
	add_the_players_area();
	add_the_vertical_separator();
	add_the_status_area();
}

FieldContainer::~FieldContainer() {

}


void FieldContainer::add_the_players_area() {
	this->player_field = new PlayingField();
	// widget, bool expand, bool fill, int margin
	this->pack_start(*player_field,true,true);
	player_field->show();
}

void FieldContainer::add_the_vertical_separator() {
	this->pack_start(vertical_separator,false,true);
	vertical_separator.show();
}

void FieldContainer::add_the_status_area() {
	this->status_field = new PlayingField();
	this->pack_end(*status_field,true,true);
	status_field->show();
}
