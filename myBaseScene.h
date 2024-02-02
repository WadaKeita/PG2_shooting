#pragma once
class BaseScene
{
public:
	BaseScene();
	~BaseScene();
	virtual void Update(char* keys, char* preKeys);
	virtual void Draw();

	int GetNextScene() { return nextScene_; }
	int GetResult() { return result_; }
	void SetResult(int result);

protected:
	enum RESULT {
		kERROR,
		kGAMECLEAR,
		kGAMEOVER,
	};

	int nextScene_;
	RESULT result_;

};

