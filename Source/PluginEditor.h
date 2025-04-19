

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ParaEQDemoAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    ParaEQDemoAudioProcessorEditor (ParaEQDemoAudioProcessor&);
    ~ParaEQDemoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override
    {
        if (audioProcessor.nextFFTBlockReady)
        {
            audioProcessor.drawNextFrameOfSpectrum();
            audioProcessor.nextFFTBlockReady = false;
            repaint();
        }
    }

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ParaEQDemoAudioProcessor& audioProcessor;
    
    void initWindowSize();
    
//    ======== DIALS ========
    juce::Slider band1GainDial;
    juce::Slider band1CutoffDial;
    juce::Slider band1QDial;
    
    juce::Slider band2GainDial;
    juce::Slider band2CutoffDial;
    juce::Slider band2QDial;

    juce::Slider band3GainDial;
    juce::Slider band3CutoffDial;
    juce::Slider band3QDial;
    
    juce::Slider band4GainDial;
    juce::Slider band4CutoffDial;
    juce::Slider band4QDial;
    
    juce::Slider band5GainDial;
    juce::Slider band5CutoffDial;
    juce::Slider band5QDial;
    
    juce::Slider band6GainDial;
    juce::Slider band6CutoffDial;
    juce::Slider band6QDial;
    
    juce::Slider band7GainDial;
    juce::Slider band7CutoffDial;
    juce::Slider band7QDial;
    
    void setSliderProps(juce::Slider &slider);
    
    std::vector<juce::Slider*> dials =
    {
        &band1GainDial, &band1CutoffDial, &band1QDial,
        &band2GainDial, &band2CutoffDial, &band2QDial,
        &band3GainDial, &band3CutoffDial, &band3QDial,
        &band4GainDial, &band4CutoffDial, &band4QDial,
        &band5GainDial, &band5CutoffDial, &band5QDial,
        &band6GainDial, &band6CutoffDial, &band6QDial,
        &band7GainDial, &band7CutoffDial, &band7QDial,
    };
    
//    ======== ATTACHMENTS ========
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band1GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band1CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band1QDialAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band2GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band2CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band2QDialAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band3GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band3CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band3QDialAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band4GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band4CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band4QDialAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band5GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band5CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band5QDialAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band6GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band6CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band6QDialAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band7GainDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band7CutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> band7QDialAttach;
    
    
//    ======== LABELS ========
    juce::Label band1Gainlabel {"Gain 1", "Gain 1"};
    juce::Label band1Cutofflabel {"Cutoff 1", "Cutoff 1"};
    juce::Label band1Qlabel {"Q 1", "Q 1"};
    
    juce::Label band2Gainlabel {"Gain 2", "Gain 2"};
    juce::Label band2Cutofflabel {"Cutoff 2", "Cutoff 2"};
    juce::Label band2Qlabel {"Q 2", "Q 2"};
    
    juce::Label band3Gainlabel {"Gain 3", "Gain 3"};
    juce::Label band3Cutofflabel {"Cutoff 3", "Cutoff 3"};
    juce::Label band3Qlabel {"Q 3", "Q 3"};
    
    juce::Label band4Gainlabel {"Gain 4", "Gain 4"};
    juce::Label band4Cutofflabel {"Cutoff 4", "Cutoff 4"};
    juce::Label band4Qlabel {"Q 4", "Q 4"};
    
    juce::Label band5Gainlabel {"Gain 5", "Gain 5"};
    juce::Label band5Cutofflabel {"Cutoff 5", "Cutoff 5"};
    juce::Label band5Qlabel {"Q 5", "Q 5"};
    
    juce::Label band6Gainlabel {"Gain 6", "Gain 6"};
    juce::Label band6Cutofflabel {"Cutoff 6", "Cutoff 6"};
    juce::Label band6Qlabel {"Q 6", "Q 6"};
    
    juce::Label band7Gainlabel {"Gain 7", "Gain 7"};
    juce::Label band7Cutofflabel {"Cutoff 7", "Cutoff 7"};
    juce::Label band7Qlabel {"Q 7", "Q 7"};
    
    void setLabelProps(juce::Label &label);
    
    std::vector<juce::Label*> labels =
    {
        &band1Gainlabel, &band1Cutofflabel, &band1Qlabel,
        &band2Gainlabel, &band2Cutofflabel, &band2Qlabel,
        &band3Gainlabel, &band3Cutofflabel, &band3Qlabel,
        &band4Gainlabel, &band4Cutofflabel, &band4Qlabel,
        &band5Gainlabel, &band5Cutofflabel, &band5Qlabel,
        &band6Gainlabel, &band6Cutofflabel, &band6Qlabel,
        &band7Gainlabel, &band7Cutofflabel, &band7Qlabel,
    };
    
    
    juce::Label graphLabel100 {"100", "100"};
    juce::Label graphLabel250 {"250", "250"};
    juce::Label graphLabel500 {"500", "500"};
    juce::Label graphLabel1000 {"1K", "1K"};
    juce::Label graphLabel2000 {"2K", "2K"};
    juce::Label graphLabel4000 {"4K", "4K"};
    juce::Label graphLabel8000 {"8K", "8K"};
    juce::Label graphLabel16000 {"16K", "16K"};

    std::vector <juce::Label*> graphLabels =
    {
        &graphLabel100, &graphLabel250, &graphLabel500,
        &graphLabel1000, &graphLabel2000, &graphLabel4000,
        &graphLabel8000, &graphLabel16000
    };
    
    
    juce::Rectangle<float> m_analyzerBounds;
    
    void drawFrame (juce::Graphics& g);
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParaEQDemoAudioProcessorEditor)
};
