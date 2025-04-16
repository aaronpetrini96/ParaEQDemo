#include "../../PluginEditor.h"

void ParaEQDemoAudioProcessorEditor::setLabelProps(juce::Label &label)
{
    addAndMakeVisible(label);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(juce::Font("Helvetica", 16.0, juce::Font::FontStyleFlags::bold));
    label.setColour(juce::Label::ColourIds::outlineColourId, juce::Colours::transparentBlack);
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white.withAlpha(0.6f));
    label.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colours::transparentBlack);
    
}
