#pragma once
namespace BTEngine
{

	class Scene;

	class SceneObject
	{
	public:
		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() const = 0;
		virtual void Initialize() = 0;

		SceneObject() = default;
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;

		void SetScene(Scene* scene) {
			m_pScene = scene;
		}

		Scene* GetScene() const {
			return m_pScene;
		};

	private:
		Scene* m_pScene;

	};
}
