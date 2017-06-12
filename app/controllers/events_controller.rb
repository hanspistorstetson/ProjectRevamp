class EventsController < ApplicationController
  before_action :find_event, only: [:show, :edit, :update, :destroy]
  before_action :authenticate_user, only: [:new, :create, :update, :edit, :destroy]

  def index
    @events = Event.all
  end

  def show

  end

  def new
    @event = Event.new
  end

  def create
    @event = Event.new event_params

    if @event.save
      redirect_to @event, flash[:success] = "You succesfully created an event"
    else
      render 'new', flash[:danger] = "Your event did not save successfully"
    end
  end


  def edit

  end

  def update
    if @event.update event_params
      redirect_to @event, flash[:success] = "Successfully updated your event"
    else
      render 'edit', flash[:danger] = "Your event was not successfully updated "
    end
  end

  def destroy
    @event.destroy
    redirect_to events_path

  end


  private

  def event_params
    params.require(:event).permit(:title, :description, :dateof)
  end

  def find_event
    @event = Event.find(params[:id])
  end

end
