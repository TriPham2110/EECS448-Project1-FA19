// -*- C++ -*-
/**
 * @file   executive.h
 * @date   06 September 2019
 * @brief  Bootstraps the GTK+ window in which our program will run.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <glibmm/refptr.h>
#include <gtkmm/application.h>
#include <gdk/gdk.h>
#include <gdkmm/pixbuf.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

// Forward Declarations
class BattleWindow;

// Executive
class Executive {

	public:

		/**
		 * @pre Successful creation of executive object.
		 * @return Program exit code.
		 * @post Program exits and reports exit code to operating system.
		 * @brief Main program thread.
		 */
		int run(int argc, char* argv[]);

		/**
		 * @brief Returns executive singleton that can be used to change game state parameters.
		 */
		static Executive* get_executive_object();
    
        void changeCursor();

		/**
		 * @brief Getter for variable that tracks whether a game is currently running.
		 * @return int (0 or 1) indicating whether the game is running.
		 */
		int get_game_in_progress_state();

		/**
		 * @brief Set game state
		 * @param[in] state Set the variable that tracks game state to 1 (game in progress) or 0 (no game in progress)
		 */
		void set_game_in_progress_state(int state);

		/**
		 * @brief Polls executive object to see which player's turn it is.
		 * @return int values: (0 or 1) indicating player
		 */
		int which_player_is_up();

		/**
		 * @brief Set the variable that tracks which player is currently making a move.
		 * @param player values: 0 (player 1) or 1 (player 2)
		 */
		void set_which_player(int player);

		/**
		 * @brief Polls executive object to see whether the turn is active.
		 * @return int (0 or 1) indicating state
		 */
		int is_a_turn_active();

		/**
		 * @brief Set the variable that tracks which player is currently making a move.
		 * @param active values: 0 (inactive) 1 (active)
		 */
		void set_turn_active(int active);

		/**
		 * @brief Called from MainMenu::on_exit_button_clicked() -- forces program exit (no memory is freed).
		 */
		void quit();

		/**
		 * @brief Returns reference to Window object from window.h
		 * @return BattleWindow* Pointer to the game's main window.
		 */
		BattleWindow* get_main_window();

		/**
		 * @brief Returns the current turn counter.
		 */
		int get_turn_count();

		/**
		 * @brief Increments turn count by one at the end of each turn.
		 */
		void increment_turn_count();

		/**
		 * @brief Used to set the turn counter back to zero at the end of the game or when it restarts.
		 */
		void set_turn_counter(int count);

		/**
		 * @brief Stores the number of ships the players want to play with.
		 */
		void set_ship_count(int count);

		/**
		 * @brief Accessor for shipCount.
		 */
		int get_ship_count();

		/**
		 * @brief Set target row for next move.
		 */
		void set_clicked_row(int row);

		/**
		 * @brief Get target row on next move.
		 */
		int get_clicked_row();

		/**
		 * @brief Set target col for next move.
		 */
		void set_clicked_col(int col);

		/**
		 * @brief Get target col on next move.
		 */
		int get_clicked_col();
    
    

	private:

		Executive();
		Executive(const Executive &);
		~Executive();
		Executive& operator=(const Executive&);
		static Executive* m_executive_instance;
		Glib::RefPtr<Gtk::Application> app;
		BattleWindow* main_window;
		int gameInProgressState = 0;
		int whichPlayer = 0;
		int gamePausedState = 0;
		int turnActive = 0;
		int turnCount = 0;
		int shipCount = 0;
		int clicked_row = 0;
		int clicked_col = 0;
    
        GdkWindow *gdk_window;
        

};

#endif // EXECUTIVE_H_
