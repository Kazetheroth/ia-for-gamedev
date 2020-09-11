#pragma once
class World
{
public:
	

	private:
		int golds;
		int rocks;
		int wooden;
		int workers;
	public:
		int getGolds() const;
		void setGolds(int golds);
		int getRocks() const;
		void setRocks(int rocks);
		int getWooden() const;
		void setWooden(int wooden);
		int getWorkers() const;
		void setWorkers(int workers);

		World(int golds, int rocks, int wooden, int workers);
		World();
		~World();
};

