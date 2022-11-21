#pragma once
class SceneManager final
{
private:
	SceneManager();
	~SceneManager();
public://メンバ関数
	//コピーコンストラクタ無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子無効
	SceneManager& operator=(const SceneManager& obj) = delete;

	//インスタンスにアクセスするための関数
	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

public://メンバ変数
	int sceneNo = 0;
};

