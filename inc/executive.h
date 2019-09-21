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

// Forward Declarations
class BattleWindow;

// Executive
class Executive {

	public:

		/**
		 * @post Executive object is created.
		 * @brief Executive constructor.
		 */
		Executive();

		/**
		 * @post Executive object is created.
		 * @param argc The count of command-line arguments passed in.
		 * @param argv The vector of command-line arguments passed in.
		 * @brief Alternative constructor.
		 */
		Executive(int argc, char* argv[]);

		/**
		 * @brief Executive destructor.
		 */
		~Executive();

		/**
		 * @pre Successful creation of executive object.
		 * @return Program exit code.
		 * @post Program exits and reports exit code to operating system.
		 * @brief Main program thread.
		 */
		int run();

		/**
		 * @brief Returns executive singleton that can be used to change game state parameters.
		 */
		static Executive* get_executive_object();

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
		 * @brief
		 */
		int get_game_paused_state();

		/**
		 * @brief Setter for variable that tracks whether game is paused. (0 - play, 1 - paused)
		 * @param state Set the variable that tracks whether game is paused. Expects 0 (no) or 1 (yes)
		 */
		void set_game_paused_state(int state);

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

	private:

		Glib::RefPtr<Gtk::Application> app;
		BattleWindow* main_window;
		int gameInProgressState = 0;
		int whichPlayer = 0;
		int gamePausedState = 0;
		int turnActive = 0;

};

#endif // EXECUTIVE_H_
