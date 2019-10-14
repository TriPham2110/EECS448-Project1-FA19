// -*- C++ -*-
/**
* @file   executive.cpp
* @date   11 September 2019
* @brief
*/

#include "executive.h"
#include "window.h"

#include <iostream>

Executive* Executive::m_executive_instance = nullptr;

Executive::Executive() {

}

Executive::~Executive() {
}

void Executive::changeCursor(){
    
    /*
    GError* err = NULL;
    GdkPixbuf* b = gdk_pixbuf_new_from_file("img/water.png", &err );
    
    gdk_window = gtk_widget_get_window(GTK_WIDGET(main_window));
    
    GdkCursor* c = gdk_cursor_new_from_pixbuf( gdk_display_get_default() , b, 0, 0);
    
    
    if(!c)
        std::cout << "this is only a test" << std::endl;
    else
        gdk_window_set_cursor(gdk_window , c);
    
    while(gtk_events_pending ()) { gtk_main_iteration (); }
    
    */
    
    
}

Executive* Executive::get_executive_object() {
	static Executive exec;
	return &exec;
}



int Executive::run(int argc, char* argv[]) {
	app = Gtk::Application::create(argc, argv, "eecs448.fa19.project1.tghet");
	main_window = new BattleWindow;
    
    
    
	return app->run(*main_window);
}

int Executive::which_player_is_up() {
	return whichPlayer;
}

void Executive::set_which_player(int player) {
	Executive::whichPlayer = player;
}

int Executive::get_game_in_progress_state() {
	return gameInProgressState;
}

void Executive::set_game_in_progress_state(int state) {
	Executive::gameInProgressState = state;
}



int Executive::is_a_turn_active() {
	return turnActive;
}

void Executive::set_turn_active(int active) {
	Executive::turnActive = active;
}

void Executive::quit() {
	this->app->quit();
}

BattleWindow* Executive::get_main_window() {
	return main_window;
}

int Executive::get_turn_count() {
	return turnCount;
}

void Executive::increment_turn_count() {
	turnCount++;
}

void Executive::set_turn_counter(int count) {
	turnCount = count;
}

void Executive::set_ship_count(int count) {
	shipCount = count;
}

int Executive::get_ship_count() {
	return shipCount;
}

void Executive::set_clicked_row(int row) {
	clicked_row = row;
}

int Executive::get_clicked_row() {
	return clicked_row;
}

void Executive::set_clicked_col(int col) {
	clicked_col = col;
}

int Executive::get_clicked_col() {
	return clicked_col;
}
