#include "../../PluginEditor.h"

void ParaEQDemoAudioProcessorEditor::initWindowSize()
{
    juce::Rectangle<int> r = juce::Desktop::getInstance().getDisplays().getPrimaryDisplay()->userArea;
    
    int x = r.getWidth();
    auto width {0};
    
    if (x <= 1440) {
        width = x * 0.65;
    } else {
        width = x * 0.5;
    }
    
    auto height = width * 0.5;
    
    AudioProcessorEditor::setResizable(true, true);
    AudioProcessorEditor::setResizeLimits(width * 0.75, height * 0.75, width * 1.25, height * 1.25);
    AudioProcessorEditor::getConstrainer()->setFixedAspectRatio(2.0);
    
    setSize(width, height);
}
