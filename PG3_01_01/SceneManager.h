#pragma once
class SceneManager final
{
private:
	SceneManager();
	~SceneManager();
public://�����o�֐�
	//�R�s�[�R���X�g���N�^����
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q����
	SceneManager& operator=(const SceneManager& obj) = delete;

	//�C���X�^���X�ɃA�N�Z�X���邽�߂̊֐�
	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

public://�����o�ϐ�
	int sceneNo = 0;
};

