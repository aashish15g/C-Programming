//-----------------------------------------------------
// Filename: Spaceship.h
// Purpose:  The header file for the Spaceship class
// Already completed for you.
//-----------------------------------------------------

using namespace std;

class Spaceship {
	
	public:
		// Constructors
		Spaceship();
		Spaceship(const int Crew, const string Name, const string Color, const long Impulse, const bool Shields);
		Spaceship(const Spaceship &otherShip);

		// Destructor
		~Spaceship();

		// Setters (aka Mutators)
		bool SetCrewSize(const int Crew);
		void SetName(const string Name);
		void SetColor(const string Color);
		bool SetImpulseSpeed(const long Impulse);
		void SetShieldsUp(const bool Shields);

		// Getters (aka Accessors)
		int GetCrewSize() const;
		string GetName() const;
		string GetColor() const;
		long GetImpulseSpeed() const;
		bool GetShieldsUp() const;
		
		// Other
		void Print() const;
		void OrbitStart();
		void OrbitEnd();
		long CurrentSpeed() const;

	private: 
		const static long WARP_SPEED = 450000;  // speed of light in km/sec
		int crewSize;
		string name;
		string color;
		long impulseSpeed;   // cruising speed in km/sec
		bool shieldsUp;
};