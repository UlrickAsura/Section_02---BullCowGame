/* The game logic (no view code or riect user interaction)
The game is a simple guess the word game based on Mastermind
*/
#pragma once

#include <string>

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;
using FString = std::string;

enum class EGameState 
{
	Playing,
	Win,
	Lost
};

enum class EGuessStatus 
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_length,

};
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:

	// TODO create un meaning full constructor
	FBullCowGame();

	EGameState GetGameState() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	int32 GetNumberOfTriesLeft() const;
	bool  IsPlaying() const;
	bool  IsGameWon() const;

	EGuessStatus CheckGuessValidity(FText) const;
	void Reset(); 
	// provide a methode for counting bulls & cows, and increasing try # assuming the guess is valid
	BullCowCount SubmitValidGuess(FText);

protected:
	bool IsIsogram(FText) const;
	bool IsLengthValid(FText) const;
private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	EGameState MyGameState;

	// Update the game state according to the number of Bulls and Cows find and the Number of max tries
	void UpdateState(BullCowCount);
	BullCowCount CompareWord(FText,FText);
}; 