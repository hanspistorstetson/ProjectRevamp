class ActivitiesController < ApplicationController
  before_action :find_activity, only: [:show, :edit, :update, :destroy]

  def complete
    user = current_user
    activity_id = params[:activity_id]
    activity = Activity.find(activity_id)
    already_checked_in = false
    user.activities.each do |activ|
      if activ.id == activity.id
        flash[:error] = "You have already signed into " + activity.title
        already_checked_in = true
      end
    end
    if not already_checked_in
      user.activities << activity
      flash[:success] = "You have successfully shown up to" + activity.title
    end
    redirect_to activity
  end


  def index
    @activities = Activity.all
  end

  def show
    @activity = Activity.find(params[:id])

  end

  def new
    @activity = Activity.new

  end

  def create
    @activity = Activity.new activity_params


    puts params[:activity][:prereqs].class
    puts "##########"
    if @activity.save
      if params[:activity][:prereqs] != nil

        params[:activity][:prereqs].each do |prereqid|
          Prereq.create activity_id: @activity.id, prereq_id: prereqid
        end
      end

      event = Event.find(@activity.event_id)
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
    params.require(:activity).permit(:title, :description, :event_id, :prereqs)
  end

  def find_activity
    @activity = Activity.find(params[:id])
  end
end