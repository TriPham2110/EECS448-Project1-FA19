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
	add_the_moves_area();
	add_the_vertical_separator();
	add_the_status_area();
}

FieldContainer* FieldContainer::get_field_container_object() {
	static FieldContainer the_field_container;
	return &the_field_container;
}

PlayingField* FieldContainer::get_moves_field() {
	return moves_field;
}
PlayingField* FieldContainer::get_status_field() {
	return status_field;
}

FieldContainer::~FieldContainer() {

}

void FieldContainer::hide_moves_field() {
	set_field_visibility(this->moves_field, 0);
}

void FieldContainer::hide_status_field() {
	set_field_visibility(this->status_field, 0);
}

void FieldContainer::add_the_moves_area() {
	this->moves_field = new PlayingField();
	// widget, bool expand, bool fill, int margin
	this->pack_start(*moves_field,true,true);
	set_field_visibility(this->moves_field, 1);
}

void FieldContainer::add_the_vertical_separator() {
	this->pack_start(vertical_separator,false,true);
	vertical_separator.show();
}

void FieldContainer::add_the_status_area() {
	this->status_field = new PlayingField();
	this->pack_end(*status_field,true,true);
	set_field_visibility(this->status_field, 1);
}

void FieldContainer::set_field_visibility(PlayingField* field, int visibility) {
	if(visibility) {
		field->show();
	} else {
		field->hide();
	}
}
