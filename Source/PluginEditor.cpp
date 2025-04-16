
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ParaEQDemoAudioProcessorEditor::ParaEQDemoAudioProcessorEditor (ParaEQDemoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    initWindowSize();
    
// Dials props
    for (auto& dial : dials)
    {
        setSliderProps(*dial);
    }
//  Label props
    for (auto& label : labels)
    {
        setLabelProps(*label);
    }
    
//    Attach labels to dials
    for (int i {0}; i < labels.size(); ++i)
    {
        labels[i]->attachToComponent(dials[i], false);
    }
}

ParaEQDemoAudioProcessorEditor::~ParaEQDemoAudioProcessorEditor()
{
}

//==============================================================================
void ParaEQDemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(40, 42, 54));
    
    g.setColour(juce::Colours::black);
    g.fillRect(m_analyzerBounds);
}

void ParaEQDemoAudioProcessorEditor::resized()
{
    const auto leftMargin = getWidth() * 0.1;
    const auto topMargin = getHeight() * 0.58;
    const auto dialSize = getWidth() * 0.06;
    const auto spaceBetween = 1.4;
    const auto dialWidth = band1GainDial.getWidth();
    const auto dialHeight = band1GainDial.getHeight();
    auto groupSpace = 2.25;
    auto groupSpaceOffset = 1.25;
    
    m_analyzerBounds.setBounds(0, 0, getWidth(), getHeight() * 0.5);
    
    band1GainDial.setBounds(leftMargin, topMargin, dialSize, dialSize);
    band1CutoffDial.setBounds(leftMargin - dialWidth * 0.5, band1GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band1QDial.setBounds(band1CutoffDial.getX() + dialWidth, band1CutoffDial.getY(), dialSize, dialSize);

    
    band2GainDial.setBounds(leftMargin * groupSpace, topMargin, dialSize, dialSize);
    band2CutoffDial.setBounds(band2GainDial.getX() - dialWidth * 0.5, band2GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band2QDial.setBounds(band2CutoffDial.getX() + dialWidth, band2CutoffDial.getY(), dialSize, dialSize);
    groupSpace += groupSpaceOffset;
    
    band3GainDial.setBounds(leftMargin * groupSpace, topMargin, dialSize, dialSize);
    band3CutoffDial.setBounds(band3GainDial.getX() - dialWidth * 0.5, band3GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band3QDial.setBounds(band3CutoffDial.getX() + dialWidth, band3CutoffDial.getY(), dialSize, dialSize);
    groupSpace += groupSpaceOffset;
    
    band4GainDial.setBounds(leftMargin * groupSpace, topMargin, dialSize, dialSize);
    band4CutoffDial.setBounds(band4GainDial.getX() - dialWidth * 0.5, band4GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band4QDial.setBounds(band4CutoffDial.getX() + dialWidth, band4CutoffDial.getY(), dialSize, dialSize);
    groupSpace += groupSpaceOffset;
    
    band5GainDial.setBounds(leftMargin * groupSpace, topMargin, dialSize, dialSize);
    band5CutoffDial.setBounds(band5GainDial.getX() - dialWidth * 0.5, band5GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band5QDial.setBounds(band5CutoffDial.getX() + dialWidth, band5CutoffDial.getY(), dialSize, dialSize);
    groupSpace += groupSpaceOffset;
    
    band6GainDial.setBounds(leftMargin * groupSpace, topMargin, dialSize, dialSize);
    band6CutoffDial.setBounds(band6GainDial.getX() - dialWidth * 0.5, band6GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band6QDial.setBounds(band6CutoffDial.getX() + dialWidth, band6CutoffDial.getY(), dialSize, dialSize);
    groupSpace += groupSpaceOffset;
    
    band7GainDial.setBounds(leftMargin * groupSpace, topMargin, dialSize, dialSize);
    band7CutoffDial.setBounds(band7GainDial.getX() - dialWidth * 0.5, band7GainDial.getY() + dialHeight * spaceBetween, dialSize, dialSize);
    band7QDial.setBounds(band7CutoffDial.getX() + dialWidth, band7CutoffDial.getY(), dialSize, dialSize);
    groupSpace += groupSpaceOffset;
}


