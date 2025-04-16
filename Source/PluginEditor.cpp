
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ParaEQDemoAudioProcessorEditor::ParaEQDemoAudioProcessorEditor (ParaEQDemoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ParaEQDemoAudioProcessorEditor::~ParaEQDemoAudioProcessorEditor()
{
}

//==============================================================================
void ParaEQDemoAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void ParaEQDemoAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
