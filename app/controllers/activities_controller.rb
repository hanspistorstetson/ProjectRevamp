class ActivitiesController < ApplicationController
  before_action :find_activity, only: [:show, :edit, :update, :destroy]

  def index
    @activities = Activity.all
  end

  def show

  end

  def new
    @activity = Activity.new

  end

  def create

    @activity = Activity.new activity_params
    puts @activity.title
    puts @activity.description
    puts @activity.event_id

    if @activity.save
      flash[:success] = "You have created a new Activity"
      redirect_to Event.find(@activity.event_id)
    else
      flash[:danger] = "Activity creation failed. Try again"
      render 'new'
    end

  end

  def edit

  end

  def update

  end

  private

  def activity_params
    params.require(:activity).permit(:title, :description, :event_id)
  end

  def find_activity
    @activity = Activity.find(params[:id])
  end
end