#pragma once
#include "BaseComponent.h"
#include "Font.h"

class TextComponent :
    public BaseComponent
{
public:
	TextComponent(dae::GameObject* pOwner);
	virtual ~TextComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;

	TextComponent* SetText(const std::string& text);
	TextComponent* SetFont(std::shared_ptr<dae::Font> font);

private:
	bool m_NeedsUpdate;
	std::string m_Text;
	std::shared_ptr<dae::Font> m_Font;
};

